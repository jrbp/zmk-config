{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

    # zmk-nix.url = "github:lilyinstarlight/zmk-nix"; # just coppied+modifed nix dir
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    forAllSystems = nixpkgs.lib.genAttrs ["x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin"];
  in {
    lib = {
      buildersFor = pkgs: import ./nix/builders.nix {inherit (pkgs) callPackage;};
    };
    packages = forAllSystems (system: let
      pkgs = nixpkgs.legacyPackages.${system};
    in rec {
      default = firmware;

      # TODO: make more conducive to multiple keyboards in repo
      firmware = corne36_test;
      flash = pkgs.callPackage ./nix/flash.nix {inherit firmware;};
      update = pkgs.callPackage ./nix/update.nix {};

      corne36 = self.legacyPackages.${system}.buildSplitKeyboard {
        name = "corne36";
        config = "devices/corne36";
        src = nixpkgs.lib.sourceFilesBySuffices self [".conf" ".h" ".dtsi" ".keymap" ".yml"];
        board = "nice_nano_v2";
        shield = "corne_%PART%";
        shieldPartsExtra = {left = " nice_view_adapter nice_view";};

        zephyrDepsHash = "sha256-RaWV1oeF2LTs6ZW73uj9u+sOgbQNgNko6t2hex2B/IM=";

        meta = {
          description = "corne36 ZMK firmware";
          license = nixpkgs.lib.licenses.mit;
          platforms = nixpkgs.lib.platforms.all;
        };
      };
      reset = self.legacyPackages.${system}.buildSplitKeyboard {
        name = "reset";
        config = "devices/corne36";
        src = nixpkgs.lib.sourceFilesBySuffices self [".conf" ".h" ".dtsi" ".keymap" ".yml"];
        board = "nice_nano_v2";
        shield = "settings_reset";

        zephyrDepsHash = "sha256-RaWV1oeF2LTs6ZW73uj9u+sOgbQNgNko6t2hex2B/IM=";

        meta = {
          description = "reset corne36 ZMK firmware";
          license = nixpkgs.lib.licenses.mit;
          platforms = nixpkgs.lib.platforms.all;
        };
      };
      corne36_test = self.legacyPackages.${system}.buildSplitKeyboard {
        name = "corne36_test";
        config = "devices/corne36_test";
        src = nixpkgs.lib.sourceFilesBySuffices self [".conf" ".h" ".dtsi" ".keymap" ".yml"];
        board = "nice_nano_v2";
        shield = "corne_%PART%";
        shieldPartsExtra = {left = " nice_view_adapter nice_view";};

        zephyrDepsHash = "sha256-RaWV1oeF2LTs6ZW73uj9u+sOgbQNgNko6t2hex2B/IM=";

        meta = {
          description = "corne36 test ZMK firmware";
          license = nixpkgs.lib.licenses.mit;
          platforms = nixpkgs.lib.platforms.all;
        };
      };
    });

    legacyPackages = forAllSystems (system: self.lib.buildersFor nixpkgs.legacyPackages.${system});

    devShells = forAllSystems (system: let
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      default = pkgs.callPackage ./nix/shell.nix {extraPackages = [pkgs.clang-tools];};
    });
  };
}
