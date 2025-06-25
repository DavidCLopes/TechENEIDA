#  Watchdog e Recuperação Segura

Um watchdog de hardware é como um “relógio de segurança”: se o software deixar de funcionar e não o reiniciar a tempo, o watchdog considera que o sistema bloqueou e força um reinício automático.  
Isto evita que o dispositivo fique preso sem resposta, especialmente em ambientes onde não há intervenção manual.

A ideia é definir um tempo limite um pouco acima do maior intervalo esperado entre tarefas normais. Se o sistema estiver a funcionar bem, envia sinais regulares ao watchdog.  
Se algo correr mal (como uma falha de comunicação ou leitura de dados), o watchdog deixa o tempo esgotar e reinicia o processador.

Também é possível complementar com um watchdog por software, que vigia módulos específicos (como a aquisição de sensores) e tenta recuperá-los de forma isolada.  
Se a recuperação falhar ou houver bloqueio total (deadlock), o watchdog de hardware toma conta da situação e reinicia o sistema.

No arranque, pode-se usar uma flag em memória não volátil para saber se o reset foi causado pelo watchdog. Isso permite, por exemplo, ativar um modo de segurança, restaurar valores padrão ou guardar logs para diagnóstico.

## Conclusão

Mesmo sem já ter usado num projeto real, reconheço que esta abordagem melhora bastante a robustez do sistema.  
Permite recuperar automaticamente de falhas, garantindo que o dispositivo volta a funcionar sem intervenção manual.