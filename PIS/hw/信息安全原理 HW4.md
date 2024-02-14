# 信息安全原理 HW4

> 姓名：王晨雨
>
> 学号：3200102324

实验过程：

1. 清除浏览器缓存：

   <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417133248334.png" alt="image-20230417133248334" style="zoom:67%;" />

   

   <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417133328431.png" alt="image-20230417133328431" style="zoom:50%;" /> 

2. 重启网卡服务

   <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417133612851.png" alt="image-20230417133612851" style="zoom:50%;" /> 

3. 获取目标网站服务器

   <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417133651170.png" alt="image-20230417133651170" style="zoom:67%;" /> 

4. 配置wireshark

   配置filter：

   <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417140030270.png" alt="image-20230417140030270" style="zoom:50%;" />

5. 开始抓包：

   <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417141535961.png" alt="image-20230417141535961" style="zoom:67%;" />

6. 分析抓包结果：

   1. TCP三次握手协议：

      本机向目标服务器发送同步请求，将Flags字段的Sym设置为Set

      <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417141552493.png" alt="image-20230417141552493" style="zoom:50%;" />

      目标服务器向本机回复一个ACK包，其中Syn和Acknowledgment都为Set

      <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417141622019.png" alt="image-20230417141622019" style="zoom:50%;" />

      最后，本机向目标服务器发送一个ACK包，Flag和ACknowledgment设置为Set。成功连接。

      <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417141642359.png" alt="image-20230417141642359" style="zoom:50%;" />

   2. HTTP请求

      `GET`请求

      <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417141454632.png" alt="image-20230417141454632" style="zoom:50%;" />

      目标服务器返回ACK：

      <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417141515140.png" alt="image-20230417141515140" style="zoom:50%;" />

   3. 断开TCP

      ![image-20230417141409910](C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20230417141409910.png)

