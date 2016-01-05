var mininalSpanningTree = [
{"id":"E1","source":"N0","target":"N1"},
{"id":"E2","source":"N0","target":"N3"},
//{"id":"E3","source":"N0","target":"N246"},
{"id":"E4","source":"N1","target":"N2"},
{"id":"E5","source":"N1","target":"N5"},
{"id":"E6","source":"N2","target":"N4"},
{"id":"E7","source":"N2","target":"N22"},
{"id":"E8","source":"N2","target":"N65"},
{"id":"E9","source":"N2","target":"N108"},
{"id":"E10","source":"N2","target":"N189"},
{"id":"E11","source":"N4","target":"N68"},
{"id":"E12","source":"N4","target":"N77"},
{"id":"E13","source":"N4","target":"N219"},
{"id":"E14","source":"N6","target":"N7"},
{"id":"E15","source":"N6","target":"N74"},
{"id":"E16","source":"N6","target":"N132"},
{"id":"E17","source":"N6","target":"N161"},
{"id":"E18","source":"N7","target":"N18"},
{"id":"E19","source":"N7","target":"N87"},
{"id":"E20","source":"N7","target":"N124"},
{"id":"E21","source":"N7","target":"N194"},
{"id":"E22","source":"N7","target":"N196"},
{"id":"E23","source":"N7","target":"N235"},
{"id":"E24","source":"N9","target":"N8"},
{"id":"E25","source":"N10","target":"N12"},
{"id":"E26","source":"N11","target":"N10"},
{"id":"E27","source":"N12","target":"N21"},
{"id":"E28","source":"N13","target":"N9"},
{"id":"E29","source":"N14","target":"N49"},
{"id":"E30","source":"N14","target":"N58"},
{"id":"E31","source":"N14","target":"N61"},
{"id":"E32","source":"N14","target":"N67"},
{"id":"E33","source":"N14","target":"N90"},
{"id":"E34","source":"N14","target":"N110"},
{"id":"E35","source":"N14","target":"N152"},
{"id":"E36","source":"N14","target":"N242"},
{"id":"E37","source":"N15","target":"N6"},
{"id":"E38","source":"N15","target":"N14"},
{"id":"E39","source":"N15","target":"N33"},
{"id":"E40","source":"N15","target":"N34"},
{"id":"E41","source":"N15","target":"N50"},
{"id":"E42","source":"N15","target":"N73"},
{"id":"E43","source":"N15","target":"N104"},
{"id":"E44","source":"N15","target":"N131"},
{"id":"E45","source":"N15","target":"N147"},
{"id":"E46","source":"N16","target":"N17"},
{"id":"E47","source":"N16","target":"N19"},
{"id":"E48","source":"N16","target":"N28"},
{"id":"E49","source":"N16","target":"N29"},
{"id":"E50","source":"N17","target":"N44"},
{"id":"E51","source":"N17","target":"N78"},
{"id":"E52","source":"N17","target":"N222"},
{"id":"E53","source":"N18","target":"N166"},
{"id":"E54","source":"N19","target":"N40"},
{"id":"E55","source":"N21","target":"N20"},
{"id":"E56","source":"N21","target":"N83"},
{"id":"E57","source":"N21","target":"N154"},
{"id":"E58","source":"N22","target":"N23"},
{"id":"E59","source":"N22","target":"N26"},
{"id":"E60","source":"N22","target":"N27"},
{"id":"E61","source":"N22","target":"N57"},
{"id":"E62","source":"N23","target":"N199"},
{"id":"E63","source":"N24","target":"N11"},
{"id":"E64","source":"N24","target":"N25"},
{"id":"E65","source":"N24","target":"N36"},
{"id":"E66","source":"N24","target":"N48"},
{"id":"E67","source":"N26","target":"N31"},
{"id":"E68","source":"N28","target":"N63"},
{"id":"E69","source":"N29","target":"N15"},
{"id":"E70","source":"N29","target":"N111"},
{"id":"E71","source":"N29","target":"N203"},
{"id":"E72","source":"N29","target":"N221"},
{"id":"E73","source":"N31","target":"N30"},
{"id":"E74","source":"N32","target":"N38"},
{"id":"E75","source":"N32","target":"N45"},
{"id":"E76","source":"N32","target":"N55"},
{"id":"E77","source":"N32","target":"N72"},
{"id":"E78","source":"N32","target":"N91"},
{"id":"E79","source":"N32","target":"N98"},
{"id":"E80","source":"N32","target":"N168"},
{"id":"E81","source":"N32","target":"N185"},
{"id":"E82","source":"N32","target":"N193"},
{"id":"E83","source":"N33","target":"N24"},
{"id":"E84","source":"N33","target":"N32"},
{"id":"E85","source":"N33","target":"N82"},
{"id":"E86","source":"N34","target":"N64"},
{"id":"E87","source":"N35","target":"N16"},
{"id":"E88","source":"N35","target":"N41"},
{"id":"E89","source":"N35","target":"N54"},
{"id":"E90","source":"N36","target":"N37"},
{"id":"E91","source":"N36","target":"N43"},
{"id":"E92","source":"N36","target":"N181"},
{"id":"E93","source":"N38","target":"N39"},
{"id":"E94","source":"N38","target":"N96"},
{"id":"E95","source":"N38","target":"N133"},
{"id":"E96","source":"N38","target":"N173"},
{"id":"E97","source":"N38","target":"N215"},
{"id":"E98","source":"N39","target":"N42"},
{"id":"E99","source":"N39","target":"N69"},
{"id":"E100","source":"N39","target":"N92"},
{"id":"E101","source":"N39","target":"N130"},
{"id":"E102","source":"N39","target":"N149"},
{"id":"E103","source":"N39","target":"N214"},
{"id":"E104","source":"N40","target":"N101"},
{"id":"E105","source":"N40","target":"N186"},
{"id":"E106","source":"N41","target":"N102"},
{"id":"E107","source":"N42","target":"N51"},
{"id":"E108","source":"N42","target":"N60"},
{"id":"E109","source":"N42","target":"N105"},
{"id":"E110","source":"N42","target":"N134"},
{"id":"E111","source":"N42","target":"N153"},
{"id":"E112","source":"N43","target":"N79"},
{"id":"E113","source":"N43","target":"N85"},
{"id":"E114","source":"N43","target":"N192"},
{"id":"E115","source":"N44","target":"N75"},
{"id":"E116","source":"N44","target":"N227"},
{"id":"E117","source":"N46","target":"N47"},
{"id":"E118","source":"N46","target":"N84"},
{"id":"E119","source":"N46","target":"N122"},
{"id":"E120","source":"N46","target":"N160"},
{"id":"E121","source":"N46","target":"N198"},
{"id":"E122","source":"N47","target":"N52"},
{"id":"E123","source":"N47","target":"N89"},
{"id":"E124","source":"N47","target":"N224"},
{"id":"E125","source":"N48","target":"N103"},
{"id":"E126","source":"N48","target":"N187"},
{"id":"E127","source":"N48","target":"N234"},
{"id":"E128","source":"N49","target":"N59"},
{"id":"E129","source":"N49","target":"N66"},
{"id":"E130","source":"N49","target":"N95"},
{"id":"E131","source":"N52","target":"N53"},
{"id":"E132","source":"N54","target":"N212"},
{"id":"E133","source":"N57","target":"N35"},
{"id":"E134","source":"N57","target":"N56"},
{"id":"E135","source":"N57","target":"N138"},
{"id":"E136","source":"N57","target":"N191"},
{"id":"E137","source":"N57","target":"N205"},
{"id":"E138","source":"N57","target":"N206"},
{"id":"E139","source":"N57","target":"N244"},
{"id":"E140","source":"N59","target":"N146"},
{"id":"E141","source":"N61","target":"N13"},
{"id":"E142","source":"N61","target":"N62"},
{"id":"E143","source":"N61","target":"N81"},
{"id":"E144","source":"N61","target":"N88"},
{"id":"E145","source":"N61","target":"N93"},
{"id":"E146","source":"N61","target":"N109"},
{"id":"E147","source":"N61","target":"N116"},
{"id":"E148","source":"N61","target":"N119"},
{"id":"E149","source":"N61","target":"N128"},
{"id":"E150","source":"N61","target":"N174"},
{"id":"E151","source":"N61","target":"N182"},
{"id":"E152","source":"N61","target":"N200"},
{"id":"E153","source":"N61","target":"N207"},
{"id":"E154","source":"N61","target":"N216"},
{"id":"E155","source":"N64","target":"N188"},
{"id":"E156","source":"N69","target":"N46"},
{"id":"E157","source":"N69","target":"N229"},
{"id":"E158","source":"N70","target":"N180"},
{"id":"E159","source":"N71","target":"N70"},
{"id":"E160","source":"N71","target":"N118"},
{"id":"E161","source":"N71","target":"N190"},
{"id":"E162","source":"N72","target":"N120"},
{"id":"E163","source":"N72","target":"N156"},
{"id":"E164","source":"N72","target":"N238"},
{"id":"E165","source":"N73","target":"N71"},
{"id":"E166","source":"N73","target":"N107"},
{"id":"E167","source":"N73","target":"N125"},
{"id":"E168","source":"N73","target":"N237"},
{"id":"E169","source":"N74","target":"N202"},
{"id":"E170","source":"N77","target":"N76"},
{"id":"E171","source":"N77","target":"N99"},
{"id":"E172","source":"N77","target":"N114"},
{"id":"E173","source":"N77","target":"N115"},
{"id":"E174","source":"N77","target":"N225"},
{"id":"E175","source":"N78","target":"N123"},
{"id":"E176","source":"N80","target":"N184"},
{"id":"E177","source":"N81","target":"N80"},
{"id":"E178","source":"N81","target":"N141"},
{"id":"E179","source":"N82","target":"N171"},
{"id":"E180","source":"N82","target":"N208"},
{"id":"E181","source":"N83","target":"N232"},
{"id":"E182","source":"N84","target":"N201"},
{"id":"E183","source":"N86","target":"N177"},
{"id":"E184","source":"N88","target":"N144"},
{"id":"E185","source":"N88","target":"N163"},
{"id":"E186","source":"N90","target":"N121"},
{"id":"E187","source":"N90","target":"N140"},
{"id":"E188","source":"N90","target":"N157"},
{"id":"E189","source":"N93","target":"N94"},
{"id":"E190","source":"N93","target":"N129"},
{"id":"E191","source":"N93","target":"N136"},
{"id":"E192","source":"N93","target":"N139"},
{"id":"E193","source":"N93","target":"N155"},
{"id":"E194","source":"N93","target":"N162"},
{"id":"E195","source":"N93","target":"N165"},
{"id":"E196","source":"N94","target":"N150"},
{"id":"E197","source":"N95","target":"N117"},
{"id":"E198","source":"N96","target":"N97"},
{"id":"E199","source":"N96","target":"N135"},
{"id":"E200","source":"N96","target":"N151"},
{"id":"E201","source":"N96","target":"N197"},
{"id":"E202","source":"N98","target":"N231"},
{"id":"E203","source":"N99","target":"N100"},
{"id":"E204","source":"N99","target":"N106"},
{"id":"E205","source":"N99","target":"N137"},
{"id":"E206","source":"N99","target":"N148"},
{"id":"E207","source":"N99","target":"N158"},
{"id":"E208","source":"N104","target":"N179"},
{"id":"E209","source":"N105","target":"N113"},
{"id":"E210","source":"N105","target":"N167"},
{"id":"E211","source":"N106","target":"N159"},
{"id":"E212","source":"N106","target":"N217"},
{"id":"E213","source":"N109","target":"N86"},
{"id":"E214","source":"N111","target":"N112"},
{"id":"E215","source":"N111","target":"N209"},
{"id":"E216","source":"N112","target":"N210"},
{"id":"E217","source":"N117","target":"N126"},
{"id":"E218","source":"N117","target":"N178"},
{"id":"E219","source":"N118","target":"N183"},
{"id":"E220","source":"N119","target":"N145"},
{"id":"E221","source":"N121","target":"N164"},
{"id":"E222","source":"N121","target":"N176"},
{"id":"E223","source":"N126","target":"N127"},
{"id":"E224","source":"N129","target":"N223"},
{"id":"E225","source":"N131","target":"N240"},
{"id":"E226","source":"N133","target":"N213"},
{"id":"E227","source":"N133","target":"N220"},
{"id":"E228","source":"N135","target":"N233"},
{"id":"E229","source":"N136","target":"N228"},
{"id":"E230","source":"N138","target":"N230"},
{"id":"E231","source":"N141","target":"N142"},
{"id":"E232","source":"N141","target":"N143"},
{"id":"E233","source":"N141","target":"N170"},
{"id":"E234","source":"N141","target":"N204"},
{"id":"E235","source":"N142","target":"N175"},
{"id":"E236","source":"N142","target":"N218"},
{"id":"E237","source":"N154","target":"N169"},
{"id":"E238","source":"N155","target":"N172"},
{"id":"E239","source":"N156","target":"N245"},
{"id":"E240","source":"N163","target":"N241"},
{"id":"E241","source":"N164","target":"N195"},
{"id":"E242","source":"N167","target":"N236"},
{"id":"E243","source":"N181","target":"N226"},
{"id":"E244","source":"N194","target":"N243"},
{"id":"E245","source":"N201","target":"N239"},
{"id":"E246","source":"N206","target":"N211"}
]