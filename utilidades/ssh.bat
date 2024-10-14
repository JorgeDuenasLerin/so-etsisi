@rem Utiliza el tipo de termina que minix espera
set TERM=xterm
@rem puerto 5522
@rem conexión con @localhost
@rem establece los algoritmos de cifrado e intercambio de claves
ssh -p 5522 -oKexAlgorithms=+diffie-hellman-group1-sha1 -oHostKeyAlgorithms=+ssh-dss -o MACs=hmac-sha1 usuario@localhost