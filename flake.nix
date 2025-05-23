{
	description = "AtCoder";

	inputs = {
		nixpkgs.url = "github:nixos/nixpkgs/24.11";
		utils.url = "github:numtide/flake-utils";
	};

	outputs = { self, nixpkgs, ... }@inputs: inputs.utils.lib.eachSystem [
		"x86_64-linux"
	] (system: let
			pkgs = import nixpkgs {
				inherit system;
				config.allowUnfree = true;
			}; 
		in {
			devShells.default = pkgs.mkShell {
				name = "atcoder";
				packages = with pkgs; [
					llvmPackages_16.libstdcxxClang
					gcc12
					bear
				];
				hardeningDisable = [ "fortify" ];
				pure=true;
			};
		});
}
