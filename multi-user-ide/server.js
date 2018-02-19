var http = require('http');
var fs = require('fs');
var exec = require('child_process').exec;

var editor = fs.readFileSync('content/editor.html');
var userlist_css = fs.readFileSync('content/firepad-userlist.css');
var userlist_js = fs.readFileSync('content/firepad-userlist.js');

var reqCount = 0;


// Potentially useful. Leaving this here just in case.
/*function strncmp ( str1, str2, lgth )
{
    var s1 = (str1+'').substr(0, lgth);
    var s2 = (str2+'').substr(0, lgth);

    return ( ( s1 == s2 ) ? 0 : ( ( s1 > s2 ) ? 1 : -1 ) );
}*/


var server = http.createServer(function (req, res)
{
	reqCount++;
	var reqName = 'req' + reqCount;
	
	// Write POST data to a new .cpp file
	req.pipe(fs.createWriteStream('./run/'+reqName+'.cpp'));
	
	if (req.method == 'POST' && req.url == "/buildCode")
	{
		// Invoke script to build and execute the cpp file
		exec("./run_cpp.sh "+reqName+".cpp", function(error, stdout, stderr)
		{
			// Reply with the output from the program
			res.writeHead(200, {'Content-Type': 'text/plain'});
			res.end(stdout);
		});
		console.log("Served build request \""+reqName+"\"");
		return;
	}
	
	/* The rest of these are all just
	 * statically served files.
	 *******************************/
	if (req.url == "/code")
	{
		console.log("content/editor.html");
		res.writeHead(200, {'Content-Type': 'text/html'});
		res.end(editor);
		return;
	}
	if (req.url == "/firepad-userlist.js")
	{
		console.log("content/firepad-userlist.js");
		res.writeHead(200, {'Content-Type': 'text/javascript'});
		res.end(userlist_js);
		return;
	}
	if (req.url == "/firepad-userlist.css")
	{
		console.log("content/firepad-userlist.css");
		res.writeHead(200, {'Content-Type': 'text/css'});
		res.end(userlist_css);
		return;
	}

	console.log("Redirecting to /code");
	res.setHeader("Location", "/code");
	res.writeHead(307, {'Content-Type': 'text'});
	res.end("");
}).listen(80);

function cleanup()
{
	// Delete all the request data
	if (reqCount > 0)
	{
		exec('bash -c "rm run/req*"', function(error, stdout, stderr)
		{
			process.exit();
		});
	}
	else process.exit();
}

process.on('SIGINT', cleanup.bind(null, {exit:true}));