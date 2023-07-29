/* 
 REST API: Best TV Shows in Genre
Query
Use the HTTP GET method to retrieve information about recent television shows.
https:/jsonmock.hackerrank.com/api/tvseries to find all the shows in a
geore. The query result is paginated. To access additional pages, append ?page=
num) to the URL where num is the page number.
The response is a JSON object with the following 5 fields:
• page: the current page of the results (Nurnber)
• per_page: the maximum number of results returned per page (Number)
• total: the total number of results (Nurnber)
.
• total pages: the total number of pages with results (Number)
data: an array of tv series records
Example of a data array object:
"name": "Game of Thrones",
"runtime_of_series": "(2011-2019)",
"certificate": "A",
"runtime_of_episodes": "57 min",
"genre": "Action, Adventure, Drama",
"imdb_rating": 9.3,
*/

const https = require('https');

function getMovieData(page){
    const baseurl=`https:/jsonmock.hackerrank.com/api/tvseries`;
    const queryparams=`page=${page}`;
    const url=`${baseurl}?${queryparams}`;
    let resultsdata='';
    https.get(url,(response)=>{
        response.on('data',(res)=>{
            resultsdata+=res;
        })
        response.on('end',()=>{
            try{
                const jsondata=JSON.parse(resultsdata);
                // destructuring to 5 fields :
                const {page,per_page,total,total_pages,data}=jsondata;
                console.log(data);
            }
            catch(error){
                console.log("Error on parsing json",error);
            }
        })
    }).on('error',()=>
    {
        console.log("error in fetching");
    });
}

const page=1;
getMovieData(page);