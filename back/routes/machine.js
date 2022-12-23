var express = require('express');
var cors = require('cors')
var router = express.Router();

/* GET users listing. */
router.get('/', function (req, res, next) {
    res.send('index');
});

router.get('/dashboard', cors(), function (req, res, next) {
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
            name: "Weizen",
            pGehalt: "123%"
        }, {
            name: "Weizen",
            pGehalt: "123%"
        }
        , {
            name: "Weizen",
            pGehalt: "123%"
        }
        , {
            name: "Weizen",
            pGehalt: "123%"
        }
        , {
            name: "Weizen",
            pGehalt: "123%"
        }
    ])
})

module.exports = router;
