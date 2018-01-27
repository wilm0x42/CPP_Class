var cheerio = require('cheerio');

var fs = require('fs');
fs.readFile('./input.html', function (err, data)
{
	if (err)
	{
		throw err; 
	}
	$ = cheerio.load(data);
	
	
	//Convert links
	$('a').each(function(i, elem)
	{
		$(this).attr("href", "http://www.cppforschool.com/assignment/" + $(this).attr("href"));
	});
	
	console.log($("div .post").html());
});