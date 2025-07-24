const express = require('express');
const ledsModel = require('../model/leds_model');
const ledsRouter = express.Router();

ledsRouter.post('/create', (request, response, next) => {
    ledsModel.create(request.body)
    .then((leds) => {
        response.status(201).json({
            message: 'LED settings created successfully',
            leds: leds
        });
    })
    .catch((error) => {
        response.status(500).json({ message: error.message });
        next(error);
    });
});

ledsRouter.put('/modify/:id', (request, response, next) => {
    ledsModel.findByIdAndUpdate({_id : request.params.id}, request.body)
    .then((leds) => {
        response.json({
            message: 'LED settings updated successfully',
            leds: leds
        });
    })
    .catch((error) => {
        response.status(500).json({ message: error.message });
        next(error);
    });
});

ledsRouter.get('/led-settings', (request, response, next) => {
    ledsModel.find()
        .then((leds) => {
            response.status(200).json(leds);
        })
        .catch((error) => {
            response.status(500).json({ message: error.message });
            next(error);
        });
});

module.exports = ledsRouter;