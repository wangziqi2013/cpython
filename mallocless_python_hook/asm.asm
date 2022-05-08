
./libmallocless_python_hook.so:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 e9 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fe9]        # 3ff8 <__gmon_start__>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 e2 2f 00 00    	push   QWORD PTR [rip+0x2fe2]        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 e3 2f 00 00 	bnd jmp QWORD PTR [rip+0x2fe3]        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nop    DWORD PTR [rax]
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	push   0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmp 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	push   0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmp 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	push   0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmp 1020 <.plt>
    106f:	90                   	nop
    1070:	f3 0f 1e fa          	endbr64 
    1074:	68 04 00 00 00       	push   0x4
    1079:	f2 e9 a1 ff ff ff    	bnd jmp 1020 <.plt>
    107f:	90                   	nop

Disassembly of section .plt.got:

0000000000001080 <__cxa_finalize@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 55 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f55]        # 3fe0 <__cxa_finalize>
    108b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Disassembly of section .plt.sec:

0000000000001090 <zsim_magic_op@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 7d 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f7d]        # 4018 <zsim_magic_op+0x2cce>
    109b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010a0 <zsim_magic_op_malloc@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 75 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f75]        # 4020 <zsim_magic_op_malloc+0x2bca>
    10ab:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010b0 <zsim_magic_op_realloc@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 6d 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f6d]        # 4028 <zsim_magic_op_realloc+0x2b3a>
    10bb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010c0 <zsim_magic_op_calloc@plt>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	f2 ff 25 65 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f65]        # 4030 <zsim_magic_op_calloc+0x2b94>
    10cb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010d0 <zsim_magic_op_free@plt>:
    10d0:	f3 0f 1e fa          	endbr64 
    10d4:	f2 ff 25 5d 2f 00 00 	bnd jmp QWORD PTR [rip+0x2f5d]        # 4038 <zsim_magic_op_free+0x2af3>
    10db:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

Disassembly of section .text:

00000000000010e0 <deregister_tm_clones>:
    10e0:	48 8d 3d 61 2f 00 00 	lea    rdi,[rip+0x2f61]        # 4048 <completed.8061>
    10e7:	48 8d 05 5a 2f 00 00 	lea    rax,[rip+0x2f5a]        # 4048 <completed.8061>
    10ee:	48 39 f8             	cmp    rax,rdi
    10f1:	74 15                	je     1108 <deregister_tm_clones+0x28>
    10f3:	48 8b 05 f6 2e 00 00 	mov    rax,QWORD PTR [rip+0x2ef6]        # 3ff0 <_ITM_deregisterTMCloneTable>
    10fa:	48 85 c0             	test   rax,rax
    10fd:	74 09                	je     1108 <deregister_tm_clones+0x28>
    10ff:	ff e0                	jmp    rax
    1101:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1108:	c3                   	ret    
    1109:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001110 <register_tm_clones>:
    1110:	48 8d 3d 31 2f 00 00 	lea    rdi,[rip+0x2f31]        # 4048 <completed.8061>
    1117:	48 8d 35 2a 2f 00 00 	lea    rsi,[rip+0x2f2a]        # 4048 <completed.8061>
    111e:	48 29 fe             	sub    rsi,rdi
    1121:	48 89 f0             	mov    rax,rsi
    1124:	48 c1 ee 3f          	shr    rsi,0x3f
    1128:	48 c1 f8 03          	sar    rax,0x3
    112c:	48 01 c6             	add    rsi,rax
    112f:	48 d1 fe             	sar    rsi,1
    1132:	74 14                	je     1148 <register_tm_clones+0x38>
    1134:	48 8b 05 ad 2e 00 00 	mov    rax,QWORD PTR [rip+0x2ead]        # 3fe8 <_ITM_registerTMCloneTable>
    113b:	48 85 c0             	test   rax,rax
    113e:	74 08                	je     1148 <register_tm_clones+0x38>
    1140:	ff e0                	jmp    rax
    1142:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    1148:	c3                   	ret    
    1149:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001150 <__do_global_dtors_aux>:
    1150:	f3 0f 1e fa          	endbr64 
    1154:	80 3d ed 2e 00 00 00 	cmp    BYTE PTR [rip+0x2eed],0x0        # 4048 <completed.8061>
    115b:	75 2b                	jne    1188 <__do_global_dtors_aux+0x38>
    115d:	55                   	push   rbp
    115e:	48 83 3d 7a 2e 00 00 	cmp    QWORD PTR [rip+0x2e7a],0x0        # 3fe0 <__cxa_finalize>
    1165:	00 
    1166:	48 89 e5             	mov    rbp,rsp
    1169:	74 0c                	je     1177 <__do_global_dtors_aux+0x27>
    116b:	48 8b 3d ce 2e 00 00 	mov    rdi,QWORD PTR [rip+0x2ece]        # 4040 <__dso_handle>
    1172:	e8 09 ff ff ff       	call   1080 <__cxa_finalize@plt>
    1177:	e8 64 ff ff ff       	call   10e0 <deregister_tm_clones>
    117c:	c6 05 c5 2e 00 00 01 	mov    BYTE PTR [rip+0x2ec5],0x1        # 4048 <completed.8061>
    1183:	5d                   	pop    rbp
    1184:	c3                   	ret    
    1185:	0f 1f 00             	nop    DWORD PTR [rax]
    1188:	c3                   	ret    
    1189:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001190 <frame_dummy>:
    1190:	f3 0f 1e fa          	endbr64 
    1194:	e9 77 ff ff ff       	jmp    1110 <register_tm_clones>

0000000000001199 <zsim_magic_op_resume_sim>:
    1199:	4d 87 db             	xchg   r11,r11
    119c:	90                   	nop
    119d:	c3                   	ret    

000000000000119e <mallocless_python_hook_PyMem_RawMalloc>:
    119e:	f3 0f 1e fa          	endbr64 
    11a2:	48 83 ec 18          	sub    rsp,0x18
    11a6:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
    11ab:	48 89 34 24          	mov    QWORD PTR [rsp],rsi
    11af:	b8 00 00 00 00       	mov    eax,0x0
    11b4:	e8 e0 ff ff ff       	call   1199 <zsim_magic_op_resume_sim>
    11b9:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    11bd:	48 8b 54 24 08       	mov    rdx,QWORD PTR [rsp+0x8]
    11c2:	48 89 c6             	mov    rsi,rax
    11c5:	89 d7                	mov    edi,edx
    11c7:	e8 d4 fe ff ff       	call   10a0 <zsim_magic_op_malloc@plt>
    11cc:	90                   	nop
    11cd:	48 83 c4 18          	add    rsp,0x18
    11d1:	c3                   	ret    

00000000000011d2 <mallocless_python_hook_PyMem_RawCalloc>:
    11d2:	f3 0f 1e fa          	endbr64 
    11d6:	48 83 ec 28          	sub    rsp,0x28
    11da:	48 89 7c 24 18       	mov    QWORD PTR [rsp+0x18],rdi
    11df:	48 89 74 24 10       	mov    QWORD PTR [rsp+0x10],rsi
    11e4:	48 89 54 24 08       	mov    QWORD PTR [rsp+0x8],rdx
    11e9:	b8 00 00 00 00       	mov    eax,0x0
    11ee:	e8 a6 ff ff ff       	call   1199 <zsim_magic_op_resume_sim>
    11f3:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    11f8:	48 8b 54 24 10       	mov    rdx,QWORD PTR [rsp+0x10]
    11fd:	89 d6                	mov    esi,edx
    11ff:	48 8b 54 24 18       	mov    rdx,QWORD PTR [rsp+0x18]
    1204:	89 d1                	mov    ecx,edx
    1206:	48 89 c2             	mov    rdx,rax
    1209:	89 cf                	mov    edi,ecx
    120b:	e8 b0 fe ff ff       	call   10c0 <zsim_magic_op_calloc@plt>
    1210:	90                   	nop
    1211:	48 83 c4 28          	add    rsp,0x28
    1215:	c3                   	ret    

0000000000001216 <mallocless_python_hook_PyMem_RawRealloc>:
    1216:	f3 0f 1e fa          	endbr64 
    121a:	48 83 ec 28          	sub    rsp,0x28
    121e:	48 89 7c 24 18       	mov    QWORD PTR [rsp+0x18],rdi
    1223:	48 89 74 24 10       	mov    QWORD PTR [rsp+0x10],rsi
    1228:	48 89 54 24 08       	mov    QWORD PTR [rsp+0x8],rdx
    122d:	b8 00 00 00 00       	mov    eax,0x0
    1232:	e8 62 ff ff ff       	call   1199 <zsim_magic_op_resume_sim>
    1237:	48 8b 54 24 08       	mov    rdx,QWORD PTR [rsp+0x8]
    123c:	48 8b 44 24 10       	mov    rax,QWORD PTR [rsp+0x10]
    1241:	89 c1                	mov    ecx,eax
    1243:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
    1248:	89 ce                	mov    esi,ecx
    124a:	48 89 c7             	mov    rdi,rax
    124d:	e8 5e fe ff ff       	call   10b0 <zsim_magic_op_realloc@plt>
    1252:	90                   	nop
    1253:	48 83 c4 28          	add    rsp,0x28
    1257:	c3                   	ret    

0000000000001258 <mallocless_python_hook_PyMem_RawFree>:
    1258:	f3 0f 1e fa          	endbr64 
    125c:	48 83 ec 18          	sub    rsp,0x18
    1260:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
    1265:	b8 00 00 00 00       	mov    eax,0x0
    126a:	e8 2a ff ff ff       	call   1199 <zsim_magic_op_resume_sim>
    126f:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    1274:	48 89 c7             	mov    rdi,rax
    1277:	e8 54 fe ff ff       	call   10d0 <zsim_magic_op_free@plt>
    127c:	90                   	nop
    127d:	48 83 c4 18          	add    rsp,0x18
    1281:	c3                   	ret    

0000000000001282 <mallocless_python_hook_PyObject_Malloc>:
    1282:	f3 0f 1e fa          	endbr64 
    1286:	48 83 ec 18          	sub    rsp,0x18
    128a:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
    128f:	48 89 34 24          	mov    QWORD PTR [rsp],rsi
    1293:	4d 87 db             	xchg   r11,r11
    1296:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    129a:	48 8b 54 24 08       	mov    rdx,QWORD PTR [rsp+0x8]
    129f:	48 89 c6             	mov    rsi,rax
    12a2:	89 d7                	mov    edi,edx
    12a4:	e8 f7 fd ff ff       	call   10a0 <zsim_magic_op_malloc@plt>
    12a9:	90                   	nop
    12aa:	48 83 c4 18          	add    rsp,0x18
    12ae:	c3                   	ret    

00000000000012af <mallocless_python_hook_PyObject_Calloc>:
    12af:	f3 0f 1e fa          	endbr64 
    12b3:	48 83 ec 28          	sub    rsp,0x28
    12b7:	48 89 7c 24 18       	mov    QWORD PTR [rsp+0x18],rdi
    12bc:	48 89 74 24 10       	mov    QWORD PTR [rsp+0x10],rsi
    12c1:	48 89 54 24 08       	mov    QWORD PTR [rsp+0x8],rdx
    12c6:	4d 87 db             	xchg   r11,r11
    12c9:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    12ce:	48 8b 54 24 10       	mov    rdx,QWORD PTR [rsp+0x10]
    12d3:	89 d6                	mov    esi,edx
    12d5:	48 8b 54 24 18       	mov    rdx,QWORD PTR [rsp+0x18]
    12da:	89 d1                	mov    ecx,edx
    12dc:	48 89 c2             	mov    rdx,rax
    12df:	89 cf                	mov    edi,ecx
    12e1:	e8 da fd ff ff       	call   10c0 <zsim_magic_op_calloc@plt>
    12e6:	90                   	nop
    12e7:	48 83 c4 28          	add    rsp,0x28
    12eb:	c3                   	ret    

00000000000012ec <mallocless_python_hook_PyObject_Realloc>:
    12ec:	f3 0f 1e fa          	endbr64 
    12f0:	48 83 ec 28          	sub    rsp,0x28
    12f4:	48 89 7c 24 18       	mov    QWORD PTR [rsp+0x18],rdi
    12f9:	48 89 74 24 10       	mov    QWORD PTR [rsp+0x10],rsi
    12fe:	48 89 54 24 08       	mov    QWORD PTR [rsp+0x8],rdx
    1303:	4d 87 db             	xchg   r11,r11
    1306:	48 8b 54 24 08       	mov    rdx,QWORD PTR [rsp+0x8]
    130b:	48 8b 44 24 10       	mov    rax,QWORD PTR [rsp+0x10]
    1310:	89 c1                	mov    ecx,eax
    1312:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
    1317:	89 ce                	mov    esi,ecx
    1319:	48 89 c7             	mov    rdi,rax
    131c:	e8 8f fd ff ff       	call   10b0 <zsim_magic_op_realloc@plt>
    1321:	90                   	nop
    1322:	48 83 c4 28          	add    rsp,0x28
    1326:	c3                   	ret    

0000000000001327 <mallocless_python_hook_PyObject_Free>:
    1327:	f3 0f 1e fa          	endbr64 
    132b:	48 83 ec 18          	sub    rsp,0x18
    132f:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
    1334:	4d 87 db             	xchg   r11,r11
    1337:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    133c:	48 89 c7             	mov    rdi,rax
    133f:	e8 8c fd ff ff       	call   10d0 <zsim_magic_op_free@plt>
    1344:	90                   	nop
    1345:	48 83 c4 18          	add    rsp,0x18
    1349:	c3                   	ret    

000000000000134a <zsim_magic_op>:
    134a:	f3 0f 1e fa          	endbr64 
    134e:	48 89 7c 24 f8       	mov    QWORD PTR [rsp-0x8],rdi
    1353:	48 8b 44 24 f8       	mov    rax,QWORD PTR [rsp-0x8]
    1358:	49 89 c2             	mov    r10,rax
    135b:	4d 87 d2             	xchg   r10,r10
    135e:	90                   	nop
    135f:	c3                   	ret    

0000000000001360 <zsim_magic_op_hello_world>:
    1360:	f3 0f 1e fa          	endbr64 
    1364:	48 83 ec 18          	sub    rsp,0x18
    1368:	c7 04 24 00 00 00 00 	mov    DWORD PTR [rsp],0x0
    136f:	48 89 e0             	mov    rax,rsp
    1372:	48 89 c7             	mov    rdi,rax
    1375:	e8 16 fd ff ff       	call   1090 <zsim_magic_op@plt>
    137a:	90                   	nop
    137b:	48 83 c4 18          	add    rsp,0x18
    137f:	c3                   	ret    

0000000000001380 <zsim_magic_op_print_str>:
    1380:	f3 0f 1e fa          	endbr64 
    1384:	48 83 ec 28          	sub    rsp,0x28
    1388:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
    138d:	c7 44 24 10 01 00 00 	mov    DWORD PTR [rsp+0x10],0x1
    1394:	00 
    1395:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    139a:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    139f:	48 8d 44 24 10       	lea    rax,[rsp+0x10]
    13a4:	48 89 c7             	mov    rdi,rax
    13a7:	e8 e4 fc ff ff       	call   1090 <zsim_magic_op@plt>
    13ac:	90                   	nop
    13ad:	48 83 c4 28          	add    rsp,0x28
    13b1:	c3                   	ret    

00000000000013b2 <zsim_magic_op_start_sim>:
    13b2:	f3 0f 1e fa          	endbr64 
    13b6:	48 83 ec 18          	sub    rsp,0x18
    13ba:	c7 04 24 02 00 00 00 	mov    DWORD PTR [rsp],0x2
    13c1:	48 89 e0             	mov    rax,rsp
    13c4:	48 89 c7             	mov    rdi,rax
    13c7:	e8 c4 fc ff ff       	call   1090 <zsim_magic_op@plt>
    13cc:	90                   	nop
    13cd:	48 83 c4 18          	add    rsp,0x18
    13d1:	c3                   	ret    

00000000000013d2 <zsim_magic_op_pause_sim>:
    13d2:	f3 0f 1e fa          	endbr64 
    13d6:	48 83 ec 18          	sub    rsp,0x18
    13da:	c7 04 24 0b 00 00 00 	mov    DWORD PTR [rsp],0xb
    13e1:	48 89 e0             	mov    rax,rsp
    13e4:	48 89 c7             	mov    rdi,rax
    13e7:	e8 a4 fc ff ff       	call   1090 <zsim_magic_op@plt>
    13ec:	90                   	nop
    13ed:	48 83 c4 18          	add    rsp,0x18
    13f1:	c3                   	ret    

00000000000013f2 <zsim_magic_op_pause_sim_alloc>:
    13f2:	f3 0f 1e fa          	endbr64 
    13f6:	48 83 ec 28          	sub    rsp,0x28
    13fa:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
    13ff:	c7 44 24 10 0d 00 00 	mov    DWORD PTR [rsp+0x10],0xd
    1406:	00 
    1407:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    140c:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    1411:	48 8d 44 24 10       	lea    rax,[rsp+0x10]
    1416:	48 89 c7             	mov    rdi,rax
    1419:	e8 72 fc ff ff       	call   1090 <zsim_magic_op@plt>
    141e:	90                   	nop
    141f:	48 83 c4 28          	add    rsp,0x28
    1423:	c3                   	ret    

0000000000001424 <zsim_magic_op_pause_sim_free>:
    1424:	f3 0f 1e fa          	endbr64 
    1428:	48 83 ec 28          	sub    rsp,0x28
    142c:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
    1431:	c7 44 24 10 0e 00 00 	mov    DWORD PTR [rsp+0x10],0xe
    1438:	00 
    1439:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    143e:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    1443:	48 8d 44 24 10       	lea    rax,[rsp+0x10]
    1448:	48 89 c7             	mov    rdi,rax
    144b:	e8 40 fc ff ff       	call   1090 <zsim_magic_op@plt>
    1450:	90                   	nop
    1451:	48 83 c4 28          	add    rsp,0x28
    1455:	c3                   	ret    

0000000000001456 <zsim_magic_op_malloc>:
    1456:	f3 0f 1e fa          	endbr64 
    145a:	48 83 ec 48          	sub    rsp,0x48
    145e:	89 7c 24 0c          	mov    DWORD PTR [rsp+0xc],edi
    1462:	48 89 34 24          	mov    QWORD PTR [rsp],rsi
    1466:	8b 44 24 0c          	mov    eax,DWORD PTR [rsp+0xc]
    146a:	89 44 24 20          	mov    DWORD PTR [rsp+0x20],eax
    146e:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    1472:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    1477:	48 8d 44 24 10       	lea    rax,[rsp+0x10]
    147c:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
    1481:	c7 44 24 30 07 00 00 	mov    DWORD PTR [rsp+0x30],0x7
    1488:	00 
    1489:	48 8d 44 24 30       	lea    rax,[rsp+0x30]
    148e:	48 89 c7             	mov    rdi,rax
    1491:	e8 fa fb ff ff       	call   1090 <zsim_magic_op@plt>
    1496:	90                   	nop
    1497:	48 83 c4 48          	add    rsp,0x48
    149b:	c3                   	ret    

000000000000149c <zsim_magic_op_calloc>:
    149c:	f3 0f 1e fa          	endbr64 
    14a0:	48 83 ec 48          	sub    rsp,0x48
    14a4:	89 7c 24 0c          	mov    DWORD PTR [rsp+0xc],edi
    14a8:	89 74 24 08          	mov    DWORD PTR [rsp+0x8],esi
    14ac:	48 89 14 24          	mov    QWORD PTR [rsp],rdx
    14b0:	8b 44 24 0c          	mov    eax,DWORD PTR [rsp+0xc]
    14b4:	89 44 24 24          	mov    DWORD PTR [rsp+0x24],eax
    14b8:	8b 44 24 08          	mov    eax,DWORD PTR [rsp+0x8]
    14bc:	89 44 24 20          	mov    DWORD PTR [rsp+0x20],eax
    14c0:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
    14c4:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    14c9:	48 8d 44 24 10       	lea    rax,[rsp+0x10]
    14ce:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
    14d3:	c7 44 24 30 08 00 00 	mov    DWORD PTR [rsp+0x30],0x8
    14da:	00 
    14db:	48 8d 44 24 30       	lea    rax,[rsp+0x30]
    14e0:	48 89 c7             	mov    rdi,rax
    14e3:	e8 a8 fb ff ff       	call   1090 <zsim_magic_op@plt>
    14e8:	90                   	nop
    14e9:	48 83 c4 48          	add    rsp,0x48
    14ed:	c3                   	ret    

00000000000014ee <zsim_magic_op_realloc>:
    14ee:	f3 0f 1e fa          	endbr64 
    14f2:	48 83 ec 58          	sub    rsp,0x58
    14f6:	48 89 7c 24 18       	mov    QWORD PTR [rsp+0x18],rdi
    14fb:	89 74 24 14          	mov    DWORD PTR [rsp+0x14],esi
    14ff:	48 89 54 24 08       	mov    QWORD PTR [rsp+0x8],rdx
    1504:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
    1509:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
    150e:	8b 44 24 14          	mov    eax,DWORD PTR [rsp+0x14]
    1512:	89 44 24 30          	mov    DWORD PTR [rsp+0x30],eax
    1516:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    151b:	48 89 44 24 28       	mov    QWORD PTR [rsp+0x28],rax
    1520:	48 8d 44 24 20       	lea    rax,[rsp+0x20]
    1525:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
    152a:	c7 44 24 40 09 00 00 	mov    DWORD PTR [rsp+0x40],0x9
    1531:	00 
    1532:	48 8d 44 24 40       	lea    rax,[rsp+0x40]
    1537:	48 89 c7             	mov    rdi,rax
    153a:	e8 51 fb ff ff       	call   1090 <zsim_magic_op@plt>
    153f:	90                   	nop
    1540:	48 83 c4 58          	add    rsp,0x58
    1544:	c3                   	ret    

0000000000001545 <zsim_magic_op_free>:
    1545:	f3 0f 1e fa          	endbr64 
    1549:	48 83 ec 48          	sub    rsp,0x48
    154d:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
    1552:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
    1557:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    155c:	48 8d 44 24 10       	lea    rax,[rsp+0x10]
    1561:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
    1566:	c7 44 24 30 0a 00 00 	mov    DWORD PTR [rsp+0x30],0xa
    156d:	00 
    156e:	48 8d 44 24 30       	lea    rax,[rsp+0x30]
    1573:	48 89 c7             	mov    rdi,rax
    1576:	e8 15 fb ff ff       	call   1090 <zsim_magic_op@plt>
    157b:	90                   	nop
    157c:	48 83 c4 48          	add    rsp,0x48
    1580:	c3                   	ret    

0000000000001581 <zsim_magic_op_append_stat_snapshot>:
    1581:	f3 0f 1e fa          	endbr64 
    1585:	48 83 ec 18          	sub    rsp,0x18
    1589:	c7 04 24 0f 00 00 00 	mov    DWORD PTR [rsp],0xf
    1590:	48 89 e0             	mov    rax,rsp
    1593:	48 89 c7             	mov    rdi,rax
    1596:	e8 f5 fa ff ff       	call   1090 <zsim_magic_op@plt>
    159b:	90                   	nop
    159c:	48 83 c4 18          	add    rsp,0x18
    15a0:	c3                   	ret    

Disassembly of section .fini:

00000000000015a4 <_fini>:
    15a4:	f3 0f 1e fa          	endbr64 
    15a8:	48 83 ec 08          	sub    rsp,0x8
    15ac:	48 83 c4 08          	add    rsp,0x8
    15b0:	c3                   	ret    
