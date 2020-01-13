'use strict';
module.exports = (sequelize, DataTypes) => {
  const Entrance = sequelize.define('Entrance', {
    direction: DataTypes.STRING
  }, {});
  Entrance.associate = function(models) {
    // associations can be defined here
  };
  return Entrance;
};