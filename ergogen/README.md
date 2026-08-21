# Ergogen notes

I like to generate and view the PCB by running, for a keyboard named `keyboard` with Ergogen configuration file `keyboard.yaml`:

```
cp keyboard.yaml config.yaml; ergogen .; rm config.yaml; killall pcbnew; pcbnew output/pcbs/*.kicad_pcb
```

I have another repo with Ergogen footprints:

https://codeberg.org/humanplayer2/ergogen_footprints
