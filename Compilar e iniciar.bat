taskkill /F /IM servidor.exe >nul 2>&1
taskkill /F /IM cliente.exe >nul 2>&1
taskkill /F /IM java.exe >nul 2>&1

cd Servidor && gcc *.c */*.c -o servidor -lws2_32 && start servidor
cd..
cd Cliente-C && gcc *.c */*.c -o cliente -lws2_32 && start cliente
cd..
cd Cliente-Java && javac *.java && cls && java Cliente

