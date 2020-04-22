Exercícios

1 - Essa pasta contém os arquivos 1.txt, 2.txt, ..., 101.txt. Mas alguém nomeou
os arquivos pulando um número! Descubra qual é ele e renomeie todos os arquivos
necessários para que os números voltem a ser consecutivos,
**sem mudar a ordem dos arquivos!**
(A ordem deles é essencial: veja o porquê rodando `ls |sort -n |xargs cat`)

2 - Nessa pasta há mais de 400 PNGs, que foram nomeados com extensão .jpg
e por isso não abrem em um certo sistema operacional... sua tarefa é corrigir
a extensão de todos esses arquivos.

3 - Baixe os sprites de todos os Pokemons da primeira geração nesta pasta.
(E exclua depois, porque ninguém aqui quer ser processado pela Nintendo.)
Até isso pode ser automatizado com um script: procure por um site que tenha uma
database de Pokemon, ache o sprite de algum deles, clique em Ver Imagem e
veja o URL do sprite. Vários sites usam padrões reconhecíveis para esses URLs,
que podem ser usados num script: esse é o caso, pelo menos, do serebii.net e
do pokemondb.net.

4 - Essa pasta contém um zip com vários arquivos S#N-E#M.mkv, em que #N
corresponde ao numéro da temporada e #M ao do episódio de uma série fictícia.
Queremos criar pastas S#N para cada temporada e mover cada arquivo para a
pasta de sua respectiva temporada.

5 - O sistema de backup automático de um servidor falhou.
Nesta pasta estão todos os arquivos de log (fictícios) do servidor.
Sua tarefa é criar um arquivo .tar.gz que inclua apenas os arquivos modificados
nas últimas 72h, e que não excedam 100KB.
