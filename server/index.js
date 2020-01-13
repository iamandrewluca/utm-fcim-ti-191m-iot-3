const express = require('express')
const { Entrance } = require('./models')

const app = express()
const port = 4000

function create(direction) {
  return Entrance.create({
    direction
  })
}

app.get('/random', (req, res) => {
  create(Math.random() > 0.5 ? 'RIGHT' : 'LEFT')
    .then(e => res.send(e))
})

app.get('/left', (req, res) => {
  create('LEFT').then(e => res.send(e))
})

app.get('/right', (req, res) => {
  create('RIGHT').then(e => res.send(e))
})

app.get('/all', (req, res) => {
  Entrance.findAll().then(r => res.send(r))
})

app.listen(port, () => console.log(`Example app listening on port ${port}!`))
