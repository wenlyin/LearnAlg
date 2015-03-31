远程登陆免密码

ssh::
	ssh user@host
	如果本地用户名与远程用户名一致，登录时可以省略用户名。
	ssh host

端口:
	SSH的默认端口是22
	ssh -p 2222 host // -p指定端口
生成钥匙对:
	ssh-keygen 默认无参数 等价于 ssh-keygen -t rsa // -t 指定加密方式

中间人攻击:
	主机收到用户请求登陆消息 ---公钥---> 用户 ----拿公钥加密密码---->
			|						|
			--正常主机接收后公钥解密---<<------给主机-----------|
	格式太费劲
		中间人 在主机发送公钥后 劫持主机公钥替换成自己的公钥 ---> 用户 ---> 中间恶人-->解密(wo c 密码泄露了)--> 拿主机
	公钥加密 ---> 主机完成登陆

公钥指纹: 公钥 MD5 值, 主机贴出来 登陆提示指纹 自行确定是否连接
	主机的公钥被接受以后，它就会被保存在文件$HOME/.ssh/known_hosts之中

authorized_keys

	记录:::  公钥登陆  ssh-keygen 生成钥匙对 -f 指定文件名;
上传到主机.ssh/authorized下  ssh user@host 'mkdir -p .ssh && cat >> .ssh/authorized_keys' < ~/.ssh/id_rsa.pub

这样如果生成名 为id_rsa应是没问题 但是如果指定名称 必须在 本地.ssh/config 下配置
 Host host名 or IP
	IdentityFile:~/.ssh/id_rsa.gt.pub
多个的时候以此列出
