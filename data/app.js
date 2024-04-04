// @title     StarMod
// @file      app.js
// @date      20240114
// @repo      https://github.com/ewowi/StarMod
// @Authors   https://github.com/ewowi/StarMod/commits/main
// @Copyright © 2024 Github StarMod Commit Authors
// @license   GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
// @license   For non GPL-v3 usage, commercial licenses must be purchased. Contact moonmodules@icloud.com

function appName() {
  return "Demo";
}

function userFun(buffer) {
  if (buffer[0]==1 && jsonValues.pview) {
    let pviewNode = gId("pview");

    return true;
  }
  return false;
}