var chai = require('chai');
var chaiHttp = require('chai-http');
var server = require('../app');
var should = chai.should();
var expect    = require("chai").expect;
chai.use(chaiHttp);


describe('app', function() {



  it('Domain required: ?dominio={DOMAIN}', function(done) {
    chai.request(server)
    .get('/raml2html?raml=https://github.com/raml2html/raml2html/blob/master/examples/helloworld.raml&version=1.0')
    .end(function(err, res){
        res.should.have.status(500);
        done();
    });
  });

  it('Invalid URL', function(done) {
    chai.request(server)
    .get('/raml2html?raml=file:///home/esgi/workspace/itau/test/raml2swagger/src/raml/cartoes.raml&dominio=test&version=1.0')
    .end(function(err, res){
        res.should.have.status(500);
        done();
    });
  });

  it('Invalid domain', function(done) {
    chai.request(server)
    .get('/raml2html?raml=https://github.com/raml2html/raml2html/blob/master/examples/helloworld.raml&dominio= &version=1.0')
    .end(function(err, res){
        res.should.have.status(500);
        done();
    });
  });

  it('Decompress file', function(done) {
    chai.request(server)
    .get('/raml2html?raml=https://github.com/raml2html/raml2html/blob/master/examples/helloworld.raml&dominio=test&version=1.0')
    .end(function(err, res){
        res.should.have.status(500);
        done();
    });
  });

});
