/* 
 Use the HTTP GET method to retrieve
information from a weather records
database. Query
https://jsonmock.hackerrank.com/api/count ries/search?region={region} &name=(keyword] 
to filter by region and name. The
query result is paginated. To access
additional pages, append &page={num} to
the URL where num is the page number.
The query response from the API is a JSON
with the following five fields:
• page: the current page
per_page: the maximum number of results
per page
total the total number of records in the
search result
• total pages: the total number of
pages to query in order to get all the results
• data, an array of JSON objects containing
weather records

 
*/

const https = require('https');

// Function to retrieve weather records from the API
function getWeatherRecords(region, keyword, page) {
  const apiUrl = `https://jsonmock.hackerrank.com/api/countries/search`;
  const queryParams = `region=${region}&name=${keyword}&page=${page}`;
  const url = `${apiUrl}?${queryParams}`;

  https.get(url, (response) => {
    let data = '';

    response.on('data', (res) => {
      data +=res;
    });

    response.on('end', () => {
      try {
        const jsonData = JSON.parse(data);

        const { page: currentPage, per_page: perPage, total, total_pages, data: weatherData } = jsonData;

        console.log(`Page ${currentPage} of ${total_pages}`);
        console.log(`Total records: ${total}`);
        console.log(weatherData);

      } catch (error) {
        console.error('Error parsing JSON:', error.message);
      }
    });
  }).on('error', (error) => {
    console.error('Error fetching weather records:', error.message);
  });
}


const region = 'Asia';
const keyword = 'IN';
const page = 1; 
getWeatherRecords(region, keyword, page);
