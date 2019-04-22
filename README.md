运行指令：
Server:
```python
rm CMakeCache.txt
cmake CMakeList.txt
make
./Siena -log "log.txt" -port 1969 -identity "127.0.0.1" &> topology.kill
```


分为３个部分，ClientReciever(用户端发出订阅信息和接受匹配到的信息）、EventSender(事件生成端和发送端）、Siena(服务器端，用于接收订阅(sub)和事件(pub)，并进行匹配并发出）

#各文件含义：

part1:基本数据结构
data_structer.h:　定义了包括sub,pub等数据结构；
Siena.h,Siena.ic,Siena.cc:主要是定义了Request，其余数据结构基本未用到（例如filter,Event,Pattern);

part2:通信方面
io.h io.icc: 主要定义两个IO异常;
Comm.h,Comm.icc,Comm.cc: 定义了底层的tcp和udp协议，包括之后用到的udpSender和udpReciever;
SieaIO.h,SienaIO.cc:　定义了数据结构的IO，将字符串转化为数据结构(sub,pub)或者相反操作；

part3:线程方面
Pthreads.h,Pthread.icc,Ptheads.cc:封装了unix线程库以及锁(mutex,condition);
concurretQueue.h:定义了消息队列，主要是用于发送；
threadPool.h:定义了发送线程的操作，c++11线程库;

part4:接口方面
SimpleSiena.h,SimpleSiena.cc:主要定义了ClientReceiver和EventSender发送和接收的接口，含有上述的udpSender和udpReciever;

part5:工具方面
chrono_time.h:计算时间差，c++11;
Util.h:log工具
generator.h,generator.cc:　sub和pub生成器，用于模拟订阅和事件;

part6:算法方面
oldrein.h,oldrein.cc,rein.h,rein.cc:定义了具体的匹配算法，嵌入在服务器中;

part7:各主体main函数
Subscriber.cpp:　发送订阅和等待接收事件;
EventSender.cpp:发送事件，可以控制发送频率;
EventServer.h,EventServer.cpp: 定义了server的操作，包括发布和订阅,内含匹配算法(rein);
main.cpp: server的主函数，包括初始化和监听reciever，用于接收订阅和事件信息，匹配线程只设置为１个;

part8:其他文件
printer.h,set_util.h:暂时未用到;
sienaconf.h:没什么;

#运行命令
make (makefile是Clion根据我的文件目录来的，所以在其他机子上先cmake CMakelist比较好，直接命令行写g++命令编译最后要加上-pthread)
./Siena -log "log.txt" -port 1969 -identity "127.0.0.1" &> topology.kill
./ClientReceiver
./EventSender
可以跟端口参数，自行修改，未加则定义成代码里的默认值。

＃ntp服务器客户端搭建参考资料
https://ken.io/note/ntp-server-deploy-time-sync
https://my.oschina.net/myaniu/blog/182959
https://www.cnblogs.com/xwdreamer/p/3448773.html

#时间函数
time.h里的clock_gettime(CLOCK_REALTIME, &tv);可以精确到纳米级别
这里我还没有试过原来用到的chrono的时间函数
为了测量pub从发送到用户接收的延迟，所以需要记录发出和收到的时间点，所以我们的Pub结构也需要有一个pub_id来记录是哪个pub，并和时间点一起存入
最后处理两个时间点文件进行处理。


#目前的问题和瓶颈:
发送时间过长：
可能原因：
1.SienaIO.h,cc里定义的数据结构编码操作过于复杂;
2.多线程操作的瓶颈: threadPool里的操作;
3.阻塞发送和异步发送(异步发送用多线程，rein.cc最后发送代码里已经注释了，现在是阻塞发送)。
4.网卡。











