# 编译并运行代码

本工程已经默认你已经安装好ROS2的调试安装环境，如果未安装环境，可以前往 blog.kaylordut.com搜索ROS相关文章，根据文章提示安装。  

本工程样例是发送端程序发送一个时间戳信息到接收端，接收端接收到该信息之后，回传给发送端，然后发送端获取当前时间，
跟这个信息的时间戳作差，得到这个消息一来一回的总时间，以此来测试ROS2通信的延迟。

## 主机发送 机器人接收

编译代码之后，在主机上运行
```bash
ros2 run ros2_latency_test send
```

机器人上运行
```bash
ros2 run ros2_latency_test receive
```
我们将会看到以下打印：
```
─ ros2 run ros2_latency_test send                                                                                                                                                                                                                         ─╯
[INFO] [1702557095.854540220] [send]: This is Send()
[INFO] [1702557096.855210305] [send]: publish a new msg
[INFO] [1702557096.857083086] [send]: duration is 2.005585ms
[INFO] [1702557097.855215299] [send]: publish a new msg
[INFO] [1702557097.856358426] [send]: duration is 1.257811ms
[INFO] [1702557098.855288524] [send]: publish a new msg
[INFO] [1702557098.856541550] [send]: duration is 1.368349ms
[INFO] [1702557099.855373825] [send]: publish a new msg
[INFO] [1702557099.856874421] [send]: duration is 1.620969ms
[INFO] [1702557100.855439896] [send]: publish a new msg
[INFO] [1702557100.856590983] [send]: duration is 1.269709ms
[INFO] [1702557101.855537578] [send]: publish a new msg
[INFO] [1702557101.856765190] [send]: duration is 1.396379ms
[INFO] [1702557102.855585125] [send]: publish a new msg
[INFO] [1702557102.856812754] [send]: duration is 1.368009ms
[INFO] [1702557103.855617219] [send]: publish a new msg
[INFO] [1702557103.856787055] [send]: duration is 1.279308ms
[INFO] [1702557104.855593498] [send]: publish a new msg
[INFO] [1702557104.856942179] [send]: duration is 1.429119ms
[INFO] [1702557105.855690687] [send]: publish a new msg
[INFO] [1702557105.857278191] [send]: duration is 1.702882ms
[INFO] [1702557106.855824613] [send]: publish a new msg
[INFO] [1702557106.857349669] [send]: duration is 1.647108ms
[INFO] [1702557107.855862110] [send]: publish a new msg
[INFO] [1702557107.857374208] [send]: duration is 1.648600ms
[INFO] [1702557108.855918197] [send]: publish a new msg
[INFO] [1702557108.857405941] [send]: duration is 1.594737ms
[INFO] [1702557109.855981032] [send]: publish a new msg
[INFO] [1702557109.857158885] [send]: duration is 1.287655ms
```
## 主机接收，机器人发送
操作方法跟上面的发送类似，执行的指令调换即可

