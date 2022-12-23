var express = require('express');
var cors = require('cors')
var router = express.Router();

var serial = require('serialport')

/* GET users listing. */
router.get('/', function (req, res, next) {
    res.send('index');
});

router.post('/dashboard', cors(), function (req, res, next) {
    console.log(req.body.mode);
});



router.get('/cocktails', cors(), function (req, res, next) {
    // send motordata 
    // send bottledata

    // send commands to arduino
    res.json([
        {
            name: "Vodka Lemon",
            pGehalt: "123%"
        }, {
            name: "Baccardi Cola",
            pGehalt: "123%"
        }, {
            name: "Pils",
            pGehalt: "123%"
        }, {
            name: "Weizen1",
            pGehalt: "123%"
        }, {
            name: "Weizen2",
            pGehalt: "123%"
        }
        , {
            name: "Weizen3",
            pGehalt: "123%"
        }
        , {
            name: "Weizen4",
            pGehalt: "123%"
        }
        , {
            name: "Weizen5",
            pGehalt: "123%"
        }
    ])
})

module.exports = router;
