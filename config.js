{
	"service" : {
	    "list" : [
		{"api" : "http", "ip" : "127.0.0.1" , "port" : 8080}
//		{"api" : "http", "ip" : "10.3.12.184" , "port" : 8080}
	    ]
	},
	"http" : {
 		"script" : "/dresses",
//		"script_names" : [ "/dresses", "/admin" ] 
		 "rewrite" : [  
  			{ "regex" : "/css(/.*)?", "pattern" : "$0" },  
  			{ "regex" : "/images(/.*)?", "pattern" : "$0" },  
  			{ "regex" : "/js(/.*)?", "pattern" : "$0" },  
 			{ "regex" : ".*" , "pattern" : "/dresses$0" }  
 		]
	},
	"file_server" : {
		"enable" : true,
		"doument_root" : "."
	},
	"views" : {  
		"paths" : [ "." ],  
		"skins" : [ ],
		"default_skin" : "mainskin"
	},
        "session" : {
                "location" : "server",
		"server" : {
                        "storage" : "files"
                }
        }  
}
