nodes.forEach(function(n){
    var id = n.label;
    var name = '';
    movies.forEach(function(m){
        if(name)
            return;
        if(m.id == id)
            name = m.name;
    });
    n.doubanID = n.label;
    n.label = name;
});
var g = ({
	"nodes" : nodes,
	"edges" : mininalSpanningTree
});
