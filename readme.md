# 图分析大作业

* _数据结构与算法（1）_（_图论_部分）
* 2015-2016学年秋季学期
* 郑莉，清华大学软件学院

详情见文档：[doc/main.pdf](https://github.com/lizy14/network-data-analysis/blob/master/doc/main.pdf)。

值得一提的成果，是用聚类算法对[豆瓣电影TOP250榜单](http://movie.douban.com/top250)进行了不依赖已有知识的自动分类。

<img alt="聚类结果可视化" src="https://github.com/lizy14/network-data-analysis/blob/master/presenter/CommunityStructure.png?raw=true" width="500"/>

1. 无耻混蛋, 禁闭岛, 盗梦空间, 机器人总动员, 贫民窟的百万富翁, 记忆碎片, 让子弹飞, 本杰明·巴顿奇事, 朗读者, 致命魔术, 阿凡达, 穆赫兰道, 蝙蝠侠：黑暗骑士, 飞屋环游记, 当幸福来敲门, 撞车, 入殓师, 三傻大闹宝莱坞, 天堂电影院, 搏击俱乐部, 黑天鹅, 窃听风暴, 国王的演讲, 月球, 蝴蝶效应, 鬼子来了, 大鱼, 玛丽和马克思, V字仇杀队, 源代码, 岁月神偷, 一一, 放牛班的春天, 暖暖内含光, 这个男人来自地球, 恐怖游轮, 海上钢琴师, 告白, 香水, 真爱至上, 大话西游之大圣娶亲, 死亡诗社, 浪潮, 断背山, 人工智能, 楚门的世界, 荒野生存, 恋恋笔记本, 忠犬八公的故事, 傲慢与偏见, 曾经, 蝙蝠侠：黑暗骑士崛起, 初恋这件小事, 廊桥遗梦, 爱在暹罗;

2. 教父, 猜火车, 低俗小说, 发条橙, 重庆森林, 阿飞正传, 七宗罪, 辛德勒的名单, 燃情岁月, 西西里的美丽传说, 英国病人, 美国丽人, 阿甘正传, 勇敢的心, 爱在日落黄昏时, 美丽心灵, 剪刀手爱德华, 这个杀手不太冷, 阳光灿烂的日子, 心灵捕手, 东邪西毒, 爱在黎明破晓前, 闻香识女人, 美丽人生, 肖申克的救赎, 天使爱美丽, 飞越疯人院, 霸王别姬, 泰坦尼克号, 甜蜜蜜, 活着, 碧海蓝天, 情书, 蓝色大门;

3. 教父3, 教父2, 指环王1：魔戒再现, 指环王2：双塔奇兵, 虎口脱险, 摩登时代, 哈利·波特与魔法石, 雨中曲, 终结者2, 控方证人, 英雄本色, 音乐之声, 冰川时代, E.T.外星人, 射雕英雄传之东成西就, 变脸, 角斗士, 纵横四海, 哪吒闹海, 上帝也疯狂, 巴黎淘气帮, 未麻的部屋, 伴我同行, 末代皇帝, 寿司之神, 迁徙的鸟, 速度与激情5, 假如爱有天意;

4. 加勒比海盗, 惊魂记, 黄金三镖客, 上帝之城, 沉默的羔羊, 罗生门, 七武士, 绿里奇迹, 卡萨布兰卡, 罗马假日, 雨人, 美国往事, 与狼共舞, 乱世佳人, 钢琴家, 魂断蓝桥, 末路狂花, 花样年华, 夜访吸血鬼, 跳出我天地, 东京物语, 帝企鹅日记;

5. 怪兽电力公司, 狮子王, 天空之城, 哈尔的移动城堡, 驯龙高手, 秒速5厘米, 风之谷, 幽灵公主, 魔女宅急便, 龙猫, 千与千寻, 玩具总动员3, 神偷奶爸, 萤火虫之墓, 无敌破坏王, 侧耳倾听, 7号房的礼物, 萤火之森, 刺猬的优雅;

6. 谍影重重2, 谍影重重3, 偷拐抢骗, 谍影重重, 猫鼠游戏, 拯救大兵瑞恩, 战争之王, 致命ID, 第六感, 卢旺达饭店, 勇闯夺命岛, 血钻, 千钧一发, 恐怖直播, 导盲犬小Q, 唐伯虎点秋香, 黑鹰坠落, 荒岛余生, 喜剧之王;

7. 疯狂原始人, 辩护人, 一次别离, 触不可及, 我是山姆, 幸福终点站, 少年派的奇幻漂流, 时空恋旅人, 超脱, 怦然心动, 遗愿清单, 借东西的小人阿莉埃蒂, 叫我第一名, 海洋, 哈利·波特与死亡圣器(下), 地球上的星星, 蝴蝶, 爱·回家, 八月迷情;

8. 饮食男女, 十二怒汉, 春光乍泄, 海盗电台, 狩猎, 杀人回忆, 牯岭街少年杀人事件, 燕尾蝶, 穿条纹睡衣的男孩, 穿越时空的少女, 小鞋子, 菊次郎的夏天, 中央车站, 阳光姐妹淘, 海豚湾, 被嫌弃的松子的一生, 素媛, 青蛇;

9. 指环王3：王者无敌, 城市之光, 黑客帝国, 黑客帝国3：矩阵革命, 喜宴, 大闹天宫, 无间道, 新龙门客栈, 可可西里, 大话西游之月光宝盒, 麦兜故事, 倩女幽魂, 枪火, 莫扎特传, 两小无猜;

10. 两杆大烟枪, 非常嫌疑犯, 追随, 完美的世界, 布达佩斯大饭店, 疯狂约会美丽都, 红辣椒, 再见列宁, 勇士, 我在伊朗长大, 不一样的天空, 忠犬八公物语, 我们俩, 我爱你;

11. 洛城机密, 梦之安魂曲, 大卫·戈尔的一生;

可以看到一些可喜的地方，比如《谍影重重》三部曲被分到了同一类下（6）；有一类下清一色全部是动画片（5）。

（除此之外还写了节点对最短路径、最小生成树等图论算法，还做了可视化，不过都没什么意思，我都懒得说）

Licensed under [WTFPL](http://www.wtfpl.net/).

<a href="http://www.wtfpl.net/"><img
       src="http://www.wtfpl.net/wp-content/uploads/2012/12/wtfpl-badge-4.png"
       width="80" height="15" alt="WTFPL" /></a>
