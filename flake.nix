{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

    zmk-nix = {
      url = "github:lilyinstarlight/zmk-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { self, nixpkgs, zmk-nix }: let
    forAllSystems = nixpkgs.lib.genAttrs (nixpkgs.lib.attrNames zmk-nix.packages);
  in {
    packages = forAllSystems (system: rec {
      default = firmware;
      firmware = corne36;

      corne36 = zmk-nix.legacyPackages.${system}.buildSplitKeyboard {
        name = "corne36";
        config = "devices/corne36";

        src = nixpkgs.lib.sourceFilesBySuffices self [ ".board" ".cmake" ".conf" ".defconfig" ".dts" ".dtsi" ".json" ".keymap" ".overlay" ".shield" ".yml" "_defconfig" ".h"];

        board = "nice_nano_v2";
        shield = "corne_%PART% nice_view_adapter nice_view";
        # Want the nice_view only on the left. Maybe define own nix function calling buildKeyboard.

        zephyrDepsHash = "sha256-IawexxUjptHPv5YNoxcSNPShapQWVZNE2jk3rHsLGIM=";

        meta = {
          description = "ZMK firmware";
          license = nixpkgs.lib.licenses.mit;
          platforms = nixpkgs.lib.platforms.all;
        };
      };

      flash = zmk-nix.packages.${system}.flash.override { inherit corne36; };
      update = zmk-nix.packages.${system}.update;
    });

    devShells = forAllSystems (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
     in {
        default = zmk-nix.devShells.${system}.default.overrideAttrs (oldAttrs: {
          buildInputs = oldAttrs.buildInputs ++ [
            pkgs.clang-tools
          ];
        });
      }
    );
  };
}
