/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:42:31 by msales-a          #+#    #+#             */
/*   Updated: 2021/10/17 12:47:08 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
   Signal     Value     Action   Comment
   ──────────────────────────────────────────────────────────────────────
   SIGHUP        1       Term    Hangup detected on controlling terminal
                                 or death of controlling process
   SIGINT        2       Term    Interrupt from keyboard
   SIGQUIT       3       Core    Quit from keyboard
   SIGILL        4       Core    Illegal Instruction
   SIGABRT       6       Core    Abort signal from abort(3)
   SIGFPE        8       Core    Floating point exception
   SIGKILL       9       Term    Kill signal
   SIGSEGV      11       Core    Invalid memory reference
   SIGPIPE      13       Term    Broken pipe: write to pipe with no
                                 readers
   SIGALRM      14       Term    Timer signal from alarm(2)

   SIGTERM      15       Term    Termination signal
   SIGUSR1   30,10,16    Term    User-defined signal 1
   SIGUSR2   31,12,17    Term    User-defined signal 2
   SIGCHLD   20,17,18    Ign     Child stopped or terminated
   SIGCONT   19,18,25    Cont    Continue if stopped
   SIGSTOP   17,19,23    Stop    Stop process
   SIGTSTP   18,20,24    Stop    Stop typed at terminal
   SIGTTIN   21,21,26    Stop    Terminal input for background process
   SIGTTOU   22,22,27    Stop    Terminal output for background process
   SIGBUS      10,7,10     Core    Bus error (bad memory access)
   SIGPOLL                 Term    Pollable event (Sys V).
                                   Synonym for SIGIO
   SIGPROF     27,27,29    Term    Profiling timer expired
   SIGSYS      12,31,12    Core    Bad argument to routine (SVr4)
   SIGTRAP        5        Core    Trace/breakpoint trap
   SIGURG      16,23,21    Ign     Urgent condition on socket (4.2BSD)
   SIGVTALRM   26,26,28    Term    Virtual alarm clock (4.2BSD)
   SIGXCPU     24,24,30    Core    CPU time limit exceeded (4.2BSD)
   SIGXFSZ     25,25,31    Core    File size limit exceeded (4.2BSD)

   SIGIOT         6        Core    IOT trap. A synonym for SIGABRT
   SIGEMT       7,-,7      Term
   SIGSTKFLT    -,16,-     Term    Stack fault on coprocessor (unused)
   SIGIO       23,29,22    Term    I/O now possible (4.2BSD)
   SIGCLD       -,-,18     Ign     A synonym for SIGCHLD
   SIGPWR      29,30,19    Term    Power failure (System V)
   SIGINFO      29,-,-             A synonym for SIGPWR
   SIGLOST      -,-,-      Term    File lock lost (unused)
   SIGWINCH    28,28,20    Ign     Window resize signal (4.3BSD, Sun)
   SIGUNUSED    -,31,-     Core    Synonymous with SIGSYS
*/

static void	handle_prompt_redisplay(int signal)
{
	(void)signal;
	g_minishell.error_status = 130;
	restore_std_fd();
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	handle_interrupt_process(int signal)
{
	(void)signal;
	g_minishell.error_status = 130;
	restore_std_fd();
	ft_putstr_fd("\n", STDERR_FILENO);
}

static void	handle_quit_process(int signal)
{
	(void)signal;
	g_minishell.error_status = 131;
	restore_std_fd();
	ft_putstr_fd("Quit (core dumped)\n", 1);
}

void	set_input_signals(void)
{
	signal(SIGINT, handle_prompt_redisplay);
	signal(SIGQUIT, SIG_IGN);
}

void	set_exec_signals(void)
{
	signal(SIGINT, handle_interrupt_process);
	signal(SIGQUIT, handle_quit_process);
}
