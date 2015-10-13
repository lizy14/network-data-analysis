/*
文件名: 
描　述: 抓取豆瓣电影 top250 榜单

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-10-13

环　境: 
*/

// runs on http://movie.douban.com/* in chrome, requires jQuery

var i=0, j=0;
var content=document.createElement('div');

for(j=0; j<250; j+=25){
    
    jQuery.ajax({
        type: "get",
        async: false,
        url: 'http://movie.douban.com/top250?start='+j,
        success: function (html) {
            content.innerHTML = html;
            var items = content.querySelectorAll('div.item')
            for(i=0; i<items.length; i++){
                var item={};
                item.rank=items[i].querySelector('div.pic em').innerText;
                item.id=items[i].querySelector('div.info div.hd a').href.match(/\d+/)[0];
                item.name=items[i].querySelector('div.info div.hd span.title').innerText;
                console.log(JSON.stringify(item)+',');
            }
        },
        error: function (err) {
            console.error(err);
        }
    });    
}
