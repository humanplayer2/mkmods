# 3D printing a 1x1 MX plate

Cf. [flatfootfox part4:](https://flatfootfox.com/ergogen-part4-footprints-cases/)

**Command line:**
  - `ergogen config.yaml`, in this directory
  - `npx @jscad/cli@1 output/cases/plate.jscad -of stla -o 1x1_plate.stl`

**Cura:**  
- Open `1x1_plate.stl`, slice it, print it, check if a switch fits.