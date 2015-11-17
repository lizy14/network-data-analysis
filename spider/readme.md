1. 获取 Top250 电影列表

    使用 Google Chrome F12 开发人员工具，在 `http://movie.douban.com/*` 网页上执行 `getMovieList.js`，并将 console 输出保存至 `data\movielist.json`

2. 获取每个电影的影评

    执行 Python 3 脚本 `getReviews.py`

3. 初步建图：对每一电影，建立“高分影评用户集合”；对每一对电影，计算交集元素个数

    执行 Python 3 脚本 `makeGraph.py`

4. 精致计算边权：对每一对电影，计算其“高分影评用户集合”的_杰卡德相似系数_

    综合使用文件编辑器、Excel，对 `data\graph.json` 进行编辑

