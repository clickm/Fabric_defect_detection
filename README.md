# Fabric_defect_detection
v1.4版本
修改日期：2018.03.29
修改说明：1.修改显示图像，将显示原图为灰度图变为彩色图
	  2.对距离较近疵点进行合并
	  3.结合GMM分类器，做误判疵点的修正
          4.界面中加入显示坐标区域
v1.5版本
修改日期：2018.04.25
修改人：ck
修改说明：1.加入警报声
	  2.更改添加路径方式
v1.6版本
修改日期：2018.06.14
修改人：ck
修改说明：1.加入摄像头采集程序,采集数据实时窗口显示
	  2.对摄像头采集数据实时检测
	  3.对存在瑕疵数据进行保存
	  4.区分传送带与布匹，传送带部分不进行检测
	  5.对程序进行优化，去除冗余代码，加快处理效率

v1.7版本
修改日期：2018.07.10
修改人：ck
修改说明：1.双摄像头采集与处理（线程形式实现）
          2.图像处理部分使用了单独的线程