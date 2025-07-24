const mongoose = require('mongoose');
const schema = mongoose.Schema;

const ledsSchema = new schema(
    {
        red : {
            type : Number,
            require : true,
            default : 0
        },
        green : {
            type : Number,
            require : true,
            default : 0
        },
        blue : {
            type : Number,
            require : true,
            default : 0
        }
    }
);

const ledsModel = mongoose.model('Leds', ledsSchema);
module.exports = ledsModel;