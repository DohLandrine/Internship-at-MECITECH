const mongoose = require('mongoose');

const schema = mongoose.Schema;

const WifiSchema = new schema(
    {
        password : {
            type : String,
            require : true,
        },
        ssid : {
            type : String,
            require : true,
        },
        createdAt : {
            type : Date,
            default : Date.now,
        }
    }
);

const WifiModel = mongoose.model('Wifi', WifiSchema);
module.exports = WifiModel;