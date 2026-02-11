# Set MSYS2 UCRT64 environment in the current PowerShell session
$env:PATH = "C:\msys64\usr\bin;C:\msys64\ucrt64\bin;$env:PATH"

# Optional: go to your project folder
# Set-Location "C:\Users\User\Projects\"

# Optional: display which compiler is active
Write-Host "Active compilers:"
gcc --version
clang --version
