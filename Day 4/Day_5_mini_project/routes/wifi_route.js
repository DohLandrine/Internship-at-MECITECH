const express = require('express');
const WifiModel = require('../model/wifi_model');
const wifiRouter = express.Router();

wifiRouter.post('/create', (request, response, next) => {
    WifiModel.create(request.body)
    .then((wifi) => {
        response.status(201).json({
            message: 'Wifi credentials created successfully',
            wifi: wifi
        });
    })
    .catch((error) => {
        response.status(500).json({ message: error.message });
        next();
    });
});

wifiRouter.put('/modify/:id', (request, response, next) => {
    WifiModel.findByIdAndUpdate({_id : request.params.id}, request.body)
    .then((wifi) => {
        response.json({
            message: 'Wifi credentials updated successfully',
            wifi: wifi
        });
    })
    .catch((error) => {
        response.status(500).json({ message: error.message });
        next(error);
    });
    ;
});

wifiRouter.get('/wifi-credentials', (request, response, next) => {
    WifiModel.find()
        .then((wifi) => {
            response.status(200).json(wifi);
        })
        .catch((error) => {
            response.status(500).json({ message: error.message });
            next();
        });
});

module.exports = wifiRouter;