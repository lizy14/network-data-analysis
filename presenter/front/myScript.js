
var s;

sigma.renderers.def = sigma.renderers.canvas

sigma.classes.graph.addMethod('neighbors',
function(nodeId) {
	var k, neighbors = {},
	index = this.allNeighborsIndex[nodeId] || {};

	for (k in index) neighbors[k] = this.nodesIndex[k];

	return neighbors;
});
// Instantiate sigma:
s = new sigma({
	graph: g,
	container: 'graph_container'
});
hideAll();
s.graph.nodes().forEach(function(n) {
	n.originalColor = n.color;
});
s.graph.edges().forEach(function(e) {
	e.originalColor = e.color;
});

//drag
var drag_ins = sigma.plugins.dragNodes(s, s.renderers[0]);

s.bind('clickNode',
function(e) {

	var nodeId = e.data.node.id;
	var toKeep = s.graph.neighbors(nodeId);
	var degree = 0;
	var detailsHTML = "";
	
	detailsHTML += ('<b>' + e.data.node.id + '</b><br>');
	detailsHTML += ('<b> * ' + '片名' + '</b><br> <div class="block_info">' + e.data.node.label+ '</div>');
    var doubanID = '';
    nodes.forEach(function(i){
        if(doubanID)
            return;
        if(i.id == e.data.node.id){
            doubanID = i.doubanID;
        }
    })
    
    detailsHTML += ('<b> * ' + '豆瓣链接' + '</b><br> <div class="block_info"><a target=_blank href="http://movie.douban.com/subject/'+doubanID+'/">' + doubanID + '</a></div>');
    

	detailsHTML += ('<b> * ' + 'neighbors' + '</b><br> <div class="block_info">');
	for (i in toKeep) {
		degree++;
		detailsHTML += (i + ', ');
	}

	detailsHTML += ('degree=' + degree + '.</div>');

	for (i in e.data.node.details) {
		detailsHTML += ('<b> * ' + i + '</b><br> <div class="block_info">' + e.data.node.details[i] + '</div>');
	}

	$('#node_info_list').html(detailsHTML);
	$('#node_info_list').slideDown();
	s.refresh();

});

s.bind('clickStage',
function(e) {
    
    drag_ins
	$('#node_info_list').html('<div class="block_info">单击节点以查看其详细信息。</div>');
	s.graph.nodes().forEach(function(n) {
		n.color = n.originalColor;
	});

	s.graph.edges().forEach(function(e) {
		e.color = e.originalColor;
	});
	s.refresh();
});

function showTree(){

	s.graph.edges().forEach(function(e) {
		e.color = e.originalColor = 'black';
	});
	s.refresh();
}

function hideAll(){

	s.graph.edges().forEach(function(e) {
		e.color = e.originalColor = 'white';
	});
	s.refresh();
}

function doPath(){
    $('#shortest_path').hide();
    
    var a =parseInt($('input#a').val().slice(1));
    var b =parseInt($('input#b').val().slice(1));
    if(a>b){
        var t;
        t=a, a=b, b=t;
    }
    var result = ShortestPath[a+'-'+b];
    if(result){
        result = result.split(',');
        var length = result[0];
        var path = result[1].trim().split('-');
        result = '<b>* 路径长度</b><div class="block_info">' + length +'</div><b>* 路径上的节点</b>';
        path.forEach(function(n){
            
            var doubanID = '';
            nodes.forEach(function(i){
                if(doubanID)
                    return;
                if(i.id == 'N'+n){
                    doubanID = i.doubanID;
                }
            })
            var name = '';
            movies.forEach(function(m){
                if(name)
                    return;
                if(m.id == doubanID)
                    name = m.name;
            });
            
            result += '<div class="block_info"><b>N'+n +'</b><br><i>'+name+'</i><br>豆瓣链接<a target=_blank href="http://movie.douban.com/subject/'+doubanID+'/">' + doubanID + '</a></div>';
        });
    }
    else
        result = "失败，请检查节点编号是否正确。";
    $('#shortest_path').html('查询 N'+a+' 到 N'+b+' 的最短路径<br>'+result).slideDown();
}