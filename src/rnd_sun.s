          .seg  "text"
          .global rnd_switch, rnd_arr, rnd_moinf, rnd_plinf, rnd_zero, test_arr
rnd_switch: 
          st     %fsr,[%sp + 0x44]
          ld     [%sp + 0x44],%o0
          set    0x40000000,%o2
          xor    %o0,%o2,%o0
          st     %o0,[%sp + 0x44]
          retl
          ld     [%sp + 0x44],%fsr

rnd_arr: 
          st     %fsr,[%sp + 0x44]
          ld     [%sp + 0x44],%o0
          set    0x3FFFFFFF,%o2
          and    %o0,%o2,%o0
          st     %o0,[%sp + 0x44]
          retl
          ld     [%sp + 0x44],%fsr

rnd_moinf: 
          st     %fsr,[%sp + 0x44]
          ld     [%sp + 0x44],%o0
          set    0xC0000000,%o2
          or     %o0,%o2,%o0
          st     %o0,[%sp + 0x44]
          retl
          ld     [%sp + 0x44],%fsr

rnd_plinf: 
          st     %fsr,[%sp + 0x44]
          ld     [%sp + 0x44],%o0
          set    0xC0000000,%o2
          or     %o0,%o2,%o0
          set    0x40000000,%o2
          xor     %o0,%o2,%o0
          st     %o0,[%sp + 0x44]
          retl
          ld     [%sp + 0x44],%fsr

rnd_zero: 
          st     %fsr,[%sp + 0x44]
          ld     [%sp + 0x44],%o0
          set    0xC0000000,%o2
          or     %o0,%o2,%o0
          set    0x80000000,%o2
          xor     %o0,%o2,%o0
          st     %o0,[%sp + 0x44]
          retl
          ld     [%sp + 0x44],%fsr

