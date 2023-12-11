#!/usr/bin/node
const request = require('request');

const film = process.argv[2];
request(`https://swapi-api.hbtn.io/api/films/${film}/`, function (error, response, body) {
    if (error) {
        console.log('Error:', error)
        return
    }
    try {
        const data = JSON.parse(body)
        const characters = data["characters"]
        characters.map((character) => {
            request(character, function (error, response, body) {
                try {
                    const pjs = JSON.parse(body)
                    console.log(pjs["name"])
                } catch (error) {
                    console.error('Error parsing Characters:', error)
                }
            })
        })
        
    } catch (error) {
        console.error('Error parsing JSON:', error)
    }
})