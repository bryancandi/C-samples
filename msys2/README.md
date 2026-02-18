## MSYS2 Setup on Windows x64 (MINGW64 & UCRT64)

```powershell
winget install MSYS2.MSYS2
```

### MSYS2
```powershell
# Update MSYS2 core system (first run).
pacman -Syu
# Close the terminal completely.
# Reopen MSYS2 shell and finish updating.
pacman -Syu
# Install MSYS build tools (make, find, etc.).
pacman -S --needed base-devel
```

### MINGW64
```powershell
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-clang
# Install the complete MINGW64 toolchain.
pacman -S mingw-w64-x86_64-toolchain
```

### UCRT64
```powershell
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-clang
# Install the complete UCRT64 toolchain.
pacman -S mingw-w64-ucrt-x86_64-toolchain
```

### CLANG64 &mdash; AddressSanitizer
*Use AddressSanitizer to detect memory errors on Windows using the MSYS2 clang64 environment.*
```powershell
# Install the CLANG64 toolchain (includes ASan runtime).
pacman -S mingw-w64-clang-x86_64-toolchain
# Compile with AddressSanitizer enabled.
clang -fsanitize=address -g -O1 input.c -o output.exe [-l<lib> ...]
# Run the instrumented executable.
.\output.exe
```

### MSVC &mdash; AddressSanitizer
*Use AddressSanitizer to detect memory errors on Windows using MSVC (Microsoft Visual Studio).*
```powershell
# Compile with AddressSanitizer enabled.
cl.exe input.c /fsanitize=address /Zi [lib ...] /link /DEBUG
# Run the instrumented executable.
.\output.exe
```

### Set Environment PATH
*Using the PowerShell scripts is safer and recommended, since it avoids overriding Windows tools globally.*

```powershell
# Use provided PowerShell scripts to load one toolchain into PATH for the current session.
.\mingw64-env.ps1   # MINGW64 (MSVCRT)
.\ucrt64-env.ps1    # UCRT64 (UCRT)
.\clang64-env.ps1   # CLANG64 (UCRT + ASan support)

# Optional: manually prepend MSYS2 paths for ad‑hoc use.
$env:PATH = "C:\msys64\usr\bin;C:\msys64\<env>\bin;$env:PATH"
```

*Only do this if you want MSYS2 tools available in every PowerShell session. (**Not Recommended**)*

```powershell
# WARNING:
# Adding C:\msys64\usr\bin globally can override built‑in Windows tools
# (find.exe, sort.exe, fc.exe, etc.).
# Only add ONE toolchain to PATH at a time.

C:\msys64\usr\bin
# AND one of:
C:\msys64\mingw64\bin
# OR
C:\msys64\ucrt64\bin
# OR
C:\msys64\clang64\bin
```

### MSVCRT vs UCRT
- [MSYS2 Environments](https://www.msys2.org/docs/environments/)
