const db = require('../database');

const saldo = {
    getById: function(id, callback) {
      return db.query('select Etunimi, Sukunimi, Saldo from asiakas join Kortti on Asiakas.idAsiakas=Kortti.idAsiakas join tili on tili.idTili=kortti.idTili where idkortti=?', [id], callback);
    }
}

module.exports = saldo;