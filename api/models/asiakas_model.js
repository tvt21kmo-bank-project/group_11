const db = require('../database');
const asiakas = {
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from asiakas where idAsiakas=?', [id], callback);
  },
  add: function(asiakas, callback) {
    console.log(asiakas);
    return db.query(
      'insert into asiakas (Etunimi, Sukunimi, Lahiosoite, Puhelinnumero) values(?,?,?,?)',
      [asiakas.Etunimi, asiakas.Sukunimi, asiakas.Lahiosoite, asiakas.Puhelinnumero],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where idAsiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set Etunimi=?, Sukunimi=?, Lahiosoite=?, Puhelinnumero=? where idAsiakas=?',
      [asiakas.Etunimi, asiakas.Sukunimi, asiakas.Lahiosoite, asiakas.Puhelinnumero, id],
      callback
    );
  }
};
module.exports = asiakas;