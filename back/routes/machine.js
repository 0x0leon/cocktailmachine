var express = require('express');
var router = express.Router();

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('index');
});

router.get('/dashboard', function(req,res,next){
    res.send('dashboard')
})

module.exports = router;
