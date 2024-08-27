# cg-shop-2025
Minimum Non-Obtuse Triangulation for Planar Straight Line Graphs

https://cgshop.ibr.cs.tu-bs.de/competition/cg-shop-2025/#problem-description

# Prerequisites
It is recommended to use [VS Code](https://code.visualstudio.com/download) as we use it for development, and the plan is to gradually set it up for our project.

Also we use the following packages:
1. `bazel` (build system)
2. `clang-format` (linter for C++ files)
3. `poetry` (packet manager for Python)
## MacOS
For Mac OS, the required packages may be installed via `brew`:
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew update 
brew install bazel clang-format pipx
pipx install poetry
poetry install
```
## Ubuntu
For Ubuntu, use the native `apt`:
```
sudo apt update
sudo apt install apt-transport-https curl gnupg clang-format pipx -y
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor >bazel-archive-keyring.gpg
sudo mv bazel-archive-keyring.gpg /usr/share/keyrings
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
sudo apt update && sudo apt install bazel -y
pipx install poetry
poetry install
```
# Installation
1. Clone the repository into the desired directory:
```
git clone git@github.com:nbykh/cg-shop-2025.git ~/my-folder-with-repos
```
2. Go to the project root folder.
3. Use `bazel` to build the project and run tests:
```
bazel test //... --test_output=all
```
