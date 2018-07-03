cd Siena
make
nohup ./Siena -log "log.txt" -port 1969 -identity "127.0.0.1" &> topology.kill &

sleep 1
cd ClientReceiver
make
nohup ./ClientReceiver &

sleep 1
cd EventSender
make
nohup ./EventSender &
