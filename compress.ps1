$lab = Read-Host "Enter the lab number"


if (Test-Path .\files\Lab0$lab-Vielma.tar) {
    $confirmation = Read-Host "The file Lab0$lab-Vielma will be overwritten. Do you want to continue? (y/n)"

    if ($confirmation -eq "n") {
        Write-Host "The script has been aborted"
        exit
    }
}

xcopy .\labs\0$lab .\Lab0$lab-Vielma /E /I /Y

tar -zcvf .\Lab0$lab-Vielma.tar.gz .\Lab0$lab-Vielma

xcopy .\Lab0$lab-Vielma.tar.gz .\files /Y

Remove-Item .\Lab0$lab-Vielma -Recurse
Remove-Item .\Lab0$lab-Vielma.tar.gz -Recurse

