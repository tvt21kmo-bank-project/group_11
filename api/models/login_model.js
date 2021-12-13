const db = require('../database');

const login={
  checkPIN: function(Korttinumero, callback) {
      return db.query('SELECT Etunimi, Sukunimi, PIN, Kortti.idTili, idKortti, Tilin_tyyppi FROM asiakas join Kortti on Asiakas.idAsiakas=Kortti.idAsiakas join tili on tili.idTili=kortti.idTili WHERE Korttinumero = ?',[Korttinumero], callback); 
    }
};
          
module.exports = login;