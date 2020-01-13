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
  create(Math.random() > 0.5 ? 'IN' : 'OUT')
    .then(e => res.send(e))
})

app.get('/in', (req, res) => {
  create('IN').then(e => res.send(e))
})

app.get('/out', (req, res) => {
  create('OUT').then(e => res.send(e))
})

app.get('/all', (req, res) => {
  Entrance.findAll().then(r => res.send(r))
})

app.listen(port, () => console.log(`Example app listening on port ${port}!`))
