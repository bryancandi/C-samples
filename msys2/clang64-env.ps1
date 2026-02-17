# Set MSYS2 CLANG64 environment in the current PowerShell session
# Necessary for Clang AddressSanitizer - memory error detector
$env:PATH = "C:\msys64\usr\bin;C:\msys64\clang64\bin;$env:PATH"

# Optional: go to your project folder
# Set-Location "C:\Users\User\Projects\"

# Optional: display which compiler is active
Write-Host "Active compiler:"
clang --version
