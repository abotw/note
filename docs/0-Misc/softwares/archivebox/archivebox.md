# ARCHIVEBOX

-   [archivebox.io](https://archivebox.io/)

## Install

### Package Manager Setup

**brew (macOS)**

1.   Install [Homebrew](https://brew.sh/#install) on your system (if not already installed).

2.   Install the ArchiveBox package using `brew`.
     ``` sh
     $ brew tap archivebox/archivebox # brew tap [options] [user/repo] [URL], Tap a formula repository.
     $ brew install archivebox
     ```

3.   Create a new empty directory and initialize your collection (can be anywhere).
     ``` sh
     $ mkdir ~/archivebox && cd ~/archivebox
     $ archivebox init --setup         # if any problems, install with pip instead
     ```

4.   Optional: Start the server then login to the Web UI [http://127.0.0.1:8000](http://127.0.0.1:8000/) ⇢ Admin.
     ``` sh
     $ archivebox server 0.0.0.0:8000
     # completely optional, CLI can always be used without running a server
     # archivebox [subcommand] [--args]
     ```

See [below](https://github.com/ArchiveBox/ArchiveBox#️-cli-usage) for more usage examples using the CLI, Web UI, or filesystem/SQL/Python to manage your archive.
See the [`homebrew-archivebox`](https://github.com/ArchiveBox/homebrew-archivebox) repo for more details about this distribution.

## Supplemental materials

-   [ ] [Quickstart @ Github Wiki](https://github.com/ArchiveBox/ArchiveBox/wiki/Quickstart), Apr 7, 2021



