var cheerio = require('cheerio');

var fs = require('fs');
fs.readFile('./input.html', function (err, data)
{
	if (err)
	{
		throw err; 
	}
	$ = cheerio.load(data);
	
	console.log($("div .post").html());
});