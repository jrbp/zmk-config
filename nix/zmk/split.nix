{
  lib,
  buildKeyboard,
  runCommand,
}: {
  name ? "${args.pname}-${args.version}",
  board,
  shield ? null,
  parts ? ["left" "right"],
  shieldPartsExtra ? {},
  centralPart ? (lib.head parts),
  enableZmkStudio ? false,
  ...
} @ args: let
  westDeps =
    args.westDeps
    or (buildKeyboard ((lib.removeAttrs args ["parts" "centralPart"])
      // {
        inherit name;
      }))
    .westDeps;
in
  runCommand name ((lib.removeAttrs args ["zephyrDepsHash" "westDeps" "westRoot" "config" "enableZmkStudio" "extraWestBuildFlags" "extraCmakeFlags" "shieldPartsExtra"])
    // {
      inherit board shield parts centralPart westDeps;
      inherit (westDeps) westRoot;
    }
    // (lib.genAttrs parts (
      part:
        buildKeyboard ((lib.removeAttrs args ["board" "shield" "parts" "centralPart" "enableZmkStudio" "shieldPartsExtra"])
          // {
            name = "${name}-${part}";
            board = lib.replaceStrings ["%PART%"] [part] board;
            shield = let
              extra = shieldPartsExtra.${part} or "";
            in
              if shield != null
              then lib.replaceStrings ["%PART%"] ["${part}${extra}"] shield
              else shield;
            enableZmkStudio =
              if part == centralPart
              then enableZmkStudio
              else false;
            inherit westDeps;
          })
    ))) ''
    mkdir $out
    for part in $parts; do
      ln -s ''${!part}/zmk.uf2 $out/zmk_"$part".uf2
      ln -s ''${!part}/debug_files $out/debug_files_"$part"
    done
  ''
