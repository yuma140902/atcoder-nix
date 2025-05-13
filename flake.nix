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
			devShells.default = pkgs.mkShell rec {
				name = "atcoder";
				packages = with pkgs; [
					clang_16
					llvmPackages_16.clang-tools
					llvmPackages_16.libcxxClang
					gcc12
					bear
				];
				hardeningDisable = [ "fortify" ];
			};
		});
}
