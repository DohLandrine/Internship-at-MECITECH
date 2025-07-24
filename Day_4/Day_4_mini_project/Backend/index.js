const bodyParser = require('body-parser');
const express = require('express');
const cors = require('cors');
app.use(cors());
const app = express();
const port = process.env.PORT || 4000;
const mongoose = require('mongoose');

const ledsRouter = require('./routes/leds_route');
const wifiRouter = require('./routes/wifi_route');

mongoose.connect(process.env.MONGO_URI)
    .then(() => console.log('MongoDB connected'))
    .catch(err => console.error('MongoDB connection error:', err));

app.use(bodyParser.json());

app.use('/leds', ledsRouter);
app.use('/wifi', wifiRouter);

app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).send('Something broke!');
});

app.get('/', (req, res) => {
  res.send('Hello World!');
});

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`);
});