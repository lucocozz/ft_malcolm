# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 15:23:20 by lucocozz          #+#    #+#              #
#    Updated: 2023/04/25 15:46:20 by lucocozz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_malcolm

SRCS =	main.c					\
		$(_ARP)					\
		$(_CLI)					\
		$(_DISPLAY)				\
		$(_NETWORK)				\
		$(_SIGNALS)				\
		$(_LIBS)

_ARP =	send_arp.c				\
		recv_arp_type_from_to.c	\
		arp_request.c			\
		arp_reply.c				\
		gratuitous_arp_reply.c	\
		unicast_arp_request.c	\
		arp_poisoning.c

_CLI =	get_cli.c

_DISPLAY =	print_mac_address.c	\
			print_ip_address.c	\
			print_ether_arp.c	\
			print_arp.c

_NETWORK =	mac_str_to_binary.c	\
			is_ip_address.c		\
			is_mac_address.c

_SIGNALS =	set_signals.c

_LIBS = libft.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPENDENCIES = $(OBJS:%.o=%.d)

SRCS_DIR = sources
LIBS_DIR = libs
OBJS_DIR = .objs
INCLUDES_DIR = includes $(LIBS:%=lib%/includes) $(LIBS:%=lib%)

LIBS =

MAKE = make
CC = clang
RM = rm -f
MKDIR = mkdir -p
DEBUG = off

CFLAGS = -MMD -Wall -Wextra -Werror
CXXFLAGS = $(INCLUDES_DIR:%=-I %)
ifeq ($(DEBUG), on)
	CXXFLAGS += -g3
endif
LDFLAGS = $(LIBS:%=-L lib%) $(LIBS:%=-l%)

vpath %.c	$(addprefix $(SRCS_DIR), /.			\
				$(addprefix /arp, /. /headers)	\
				/libs /display /network /cli /signals)

all:
	$(foreach LIB, ${LIBS}, ${MAKE} -C lib${LIB} ;)
	$(MAKE) $(NAME)

scan:
	scan-build $(MAKE)

$(NAME): $(OBJS) | $(LIBS:%=lib%.a)
	$(CC) $(CXXFLAGS) $^ -o $(NAME) $(LDFLAGS)

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c $(OBJS_DIR)/debug$(DEBUG) | $(OBJS_DIR) 
	$(CC) $(CFLAGS) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@ 

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

lib%.a:
	$(MAKE) -C $(@:%.a=%)

$(OBJS_DIR)/debug$(DEBUG): | $(OBJS_DIR)
	$(RM) $(OBJS_DIR)/debug*
	touch $@

clean:
	$(foreach LIB, $(LIBS), $(MAKE) $@ -C lib$(LIB);)
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(foreach LIB, $(LIBS), lib$(LIB)/lib$(LIB).a)

re: fclean all

.PHONY: all clean fclean re scan
