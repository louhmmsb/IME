	.global _start
	.text
_start:
	# Vamos começar lendo os números em ordem
	mov $1, %rax		#Syscall de escrita
	mov $1, %rdi		#Saida padrão
	mov $mensagem1, %rsi	#Carrega a mensagem
	mov $tamanho1, %rdx	#Carrega o tamanho da mensagem
	syscall

	mov $0, %rax		#Syscall de leitura
	mov $0, %rdi		#Na entrada padrao
	mov numero1, %rsi	#Onde colocar
	mov $8, %rdx		#Tamanho que ocupa
	syscall

	mov $1, %rax
	mov $1, %rdi
	mov $mensagem2, %rsi
	mov $tamanho2, %rdx
	syscall

	mov $60, %rax		#Encerra o programa
	xor %rdi, %rdi		#Return 0
	syscall
	
	.data
mensagem1:
	.ascii "Digite 3 numeros para calcular a media: " #Mensagem boas vindas
	tamanho1 = . - mensagem1			  #Tamanho da mensagem1
mensagem2:
	.ascii "A media dos 3 numeros e: " #Mensagem que devolve o resultado
	tamanho2 = . - mensagem2
	
	.bss
.comm numero1, 8
.comm numero2, 8
.comm numero3, 8

